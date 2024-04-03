import 'dart:developer';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import '../../data/local/cache_helper.dart';
import '../../data/models/user_model.dart';
import '../../main.dart';
import '../../presentation/generated_data/screens.dart';
part 'global_state.dart';


class GlobalCubit extends Cubit<GlobalState> {
  GlobalCubit() : super(GlobalInitial());

  static GlobalCubit get(context) => BlocProvider.of(context);

  UserModel? loginModel;
  UserModel? registerModel;

  bool isEnglish = CacheHelper.getDataFromSharedPreference(key: 'lang') == 'en'
      ? true
      : false;

  Future<void> userLogin(
      {required String email,
      required String password,
      required context}) async {
    emit(LoginLoadingState());
    FirebaseAuth.instance
        .signInWithEmailAndPassword(
      email: email,
      password: password,
    )
        .then((value) async {
      await CacheHelper.sharedPreferences.setString('uID', value.user!.uid);
      FirebaseFirestore.instance
          .collection('users')
          .doc(value.user!.uid)
          .get()
          .then((value) async {
        if (value.data()!['isEmailVerified']) {
          loginModel = UserModel.fromJson(value.data()!);
          print(loginModel!.name);
          emit(LoginSuccessState(loginModel!));
        } else {
          logout(context);
          emit(LoginErrorState(('error.toString()')));
        }
      }).catchError((error) {
        log(error.toString());
        emit(LoginErrorState((error.toString())));
      });
    }).catchError((error) {
      log(error.toString());
      emit(LoginErrorState(error.toString()));
    });
  }

  void userRegister({
    required String email,
    required String password,
    required String name,
    required String phone,
  }) {
    emit(RegisterLoadingState());
    FirebaseAuth.instance
        .createUserWithEmailAndPassword(
      email: email,
      password: password,
    )
        .then((value) {
      emit(RegisterSuccessState());
      log(value.user!.email!);
      log(value.user!.uid);
      createUser(
        email: value.user!.email!,
        name: name,
        uId: value.user!.uid,
        isEmailVerified: true,
        phone: phone,
      );
    }).catchError((error) {
      emit(RegisterErrorState(error.toString()));
      log(error.toString());
    });
  }

  void logout(context) {
    CacheHelper.clearData().then((value) {
      if (value) {
        emit(LogoutState());
        Navigator.pushNamedAndRemoveUntil(
          context,
          Screens.loginScreen,
          (route) => false,
        );
      }
    });
  }

  Future<void> createUser({
    required String email,
    required String name,
    required String uId,
    required bool isEmailVerified,
    required String phone,
  }) async {
    emit(CreateUserLoadingState());

    registerModel = UserModel(
      name: name,
      email: email,
      uId: uId,
      isEmailVerified: isEmailVerified,
      phone: phone,
    );
    FirebaseFirestore.instance
        .collection('users')
        .doc(uId)
        .set(registerModel!.toMap())
        .then((value) async {
      emit(CreateUserSuccessState());
    }).catchError((error) {
      emit(CreateUserErrorState(error.toString()));
    });
  }

  IconData suffix = Icons.visibility_outlined;
  bool isPassword = true;

  changePasswordVisibility() {
    isPassword = !isPassword;
    suffix =
        isPassword ? Icons.visibility_outlined : Icons.visibility_off_outlined;
    emit(ChangePasswordVisibilityState());
  }

  changeLanguageValue(context) async {
    delegate.changeLocale(delegate.currentLocale.languageCode == 'ar'
        ? const Locale('en')
        : const Locale('ar'));
    emit(AppChangeLanguageState());
  }

}
