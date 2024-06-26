import 'dart:developer';
import 'package:conditional_builder_null_safety/conditional_builder_null_safety.dart';
import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import '../../../business_logic/app_localization.dart';
import '../../../business_logic/global_cubit/global_cubit.dart';
import '../../../data/local/cache_helper.dart';
import '../../styles/colors.dart';
import '../../widget/defaultFormField.dart';

class LoginScreen extends StatefulWidget {
  const LoginScreen({super.key});

  @override
  State<LoginScreen> createState() => _LoginScreenState();
}

class _LoginScreenState extends State<LoginScreen> {
  var emailController = TextEditingController();

  var passwordController = TextEditingController();

  var formKey = GlobalKey<FormState>();

  @override
  Widget build(BuildContext context) {
    var bloc = GlobalCubit.get(context);
    return BlocConsumer<GlobalCubit, GlobalState>(
      listener: (context, state) async {
        if (state is LoginSuccessState) {
          log(bloc.loginModel!.name.toString());
          CacheHelper.saveDataSharedPreference(
            key: 'uId',
            value: bloc.loginModel!.uId,
          );
          CacheHelper.saveDataSharedPreference(
            key: 'email',
            value: emailController.text,
          );
          CacheHelper.saveDataSharedPreference(
            key: 'password',
            value: passwordController.text,
          );
          Navigator.pushNamedAndRemoveUntil(
            context,
            '/profile',
            (route) => false,
          );
        }
      },
      builder: (context, state) {
        return Scaffold(
          backgroundColor: AppColor.primary,
          body: LayoutBuilder(builder: (context, constraints) {
            double width = constraints.maxWidth;
            double height = constraints.maxHeight;
            return SizedBox(
              width: width,
              height: height,
              child: SingleChildScrollView(
                child: Column(
                  children: [
                    SizedBox(
                      height: height * 0.4,
                      child: const Image(
                        image: AssetImage(
                          'assets/images/logo2.png',
                        ),
                      ),
                    ),
                    Container(
                      decoration: const BoxDecoration(
                        color: AppColor.white,
                        borderRadius: BorderRadius.only(
                          topRight: Radius.circular(40.0),
                          topLeft: Radius.circular(40.0),
                        ),
                      ),
                      height: height * 0.6,
                      width: width,
                      child: Center(
                        child: Form(
                          key: formKey,
                          child: SingleChildScrollView(
                            child: Column(
                              mainAxisAlignment: MainAxisAlignment.center,
                              children: [
                                const Padding(
                                  padding: EdgeInsets.all(15.0),
                                  child: Text(
                                    'LOGIN',
                                    style: TextStyle(
                                      fontFamily: 'cairo',
                                      fontSize: 60.0,
                                      fontWeight: FontWeight.bold,
                                      color: AppColor.primary,
                                    ),
                                  ),
                                ),
                                Padding(
                                  padding: const EdgeInsets.symmetric(
                                      horizontal: 60.0),
                                  child: defaultFormField(
                                    controller: emailController,
                                    type: TextInputType.emailAddress,
                                    borderRadius: 10,
                                    validate: (String value) {
                                      if (value.isEmpty) {
                                        return AppLocalizations.of(context)!
                                            .translate(
                                                'pleaseEnterYourEmailAddress')
                                            .toString();
                                      }
                                    },
                                    onSubmit: (v){},
                                    label: AppLocalizations.of(context)!
                                        .translate('email')
                                        .toString(),
                                    prefix: Icons.email_outlined,
                                  ),
                                ),
                                const SizedBox(
                                  height: 20.0,
                                ),
                                Padding(
                                  padding: const EdgeInsets.symmetric(
                                      horizontal: 60.0),
                                  child: defaultFormField(
                                    controller: passwordController,
                                    type: TextInputType.visiblePassword,
                                    suffix: GlobalCubit.get(context).suffix,
                                    borderRadius: 10,
                                    onSubmit: (value) {
                                      if (formKey.currentState!.validate()) {
                                        GlobalCubit.get(context).userLogin(
                                          email: emailController.text,
                                          password: passwordController.text,
                                          context: context,
                                        );
                                      }
                                    },
                                    isPassword:
                                        GlobalCubit.get(context).isPassword,
                                    suffixPressed: () =>
                                        GlobalCubit.get(context)
                                            .changePasswordVisibility(),
                                    validate: (String value) {
                                      if (value.isEmpty) {
                                        return AppLocalizations.of(context)!
                                            .translate(
                                                'pleaseEnterYourPassword')
                                            .toString();
                                      }
                                    },
                                    label: AppLocalizations.of(context)!
                                        .translate('password')
                                        .toString(),
                                    prefix: Icons.lock_outline,
                                  ),
                                ),
                                SizedBox(
                                  height: height * 0.1,
                                ),
                                Padding(
                                  padding: const EdgeInsets.all(15.0),
                                  child: Row(
                                    mainAxisAlignment: MainAxisAlignment.center,
                                    children: [
                                      MaterialButton(
                                        height: 55,
                                        minWidth:
                                            MediaQuery.of(context).size.width /
                                                3,
                                        elevation: 5.0,
                                        shape: RoundedRectangleBorder(
                                            borderRadius:
                                                BorderRadius.circular(10)),
                                        onPressed: () {
                                          Navigator.pushNamed(
                                              context, '/register');
                                        },
                                        color: AppColor.button,
                                        child: Text(
                                          AppLocalizations.of(context)!
                                              .translate('register')
                                              .toString(),
                                          style: const TextStyle(
                                            fontSize: 20,
                                            fontWeight: FontWeight.bold,
                                            color: AppColor.white,
                                          ),
                                        ),
                                      ),
                                      const SizedBox(
                                        width: 50.0,
                                      ),
                                      ConditionalBuilder(
                                        condition: state is! LoginLoadingState,
                                        fallback: (context) => const Center(
                                            child: CircularProgressIndicator()),
                                        builder: (context) => MaterialButton(
                                          height: 55,
                                          minWidth: MediaQuery.of(context)
                                                  .size
                                                  .width /
                                              3,
                                          elevation: 5.0,
                                          shape: RoundedRectangleBorder(
                                              borderRadius:
                                                  BorderRadius.circular(10)),
                                          onPressed: () {
                                            if (formKey.currentState!
                                                .validate()) {
                                              GlobalCubit.get(context)
                                                  .userLogin(
                                                email: emailController.text,
                                                password:
                                                    passwordController.text,
                                                context: context,
                                              );
                                            }
                                          },
                                          color: AppColor.button,
                                          child: Text(
                                            AppLocalizations.of(context)!
                                                .translate('login')
                                                .toString(),
                                            style: const TextStyle(
                                              fontSize: 20,
                                              fontWeight: FontWeight.bold,
                                              color: AppColor.white,
                                            ),
                                          ),
                                        ),
                                      ),
                                    ],
                                  ),
                                ),
                              ],
                            ),
                          ),
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            );
          }),
        );
      },
    );
  }
}
