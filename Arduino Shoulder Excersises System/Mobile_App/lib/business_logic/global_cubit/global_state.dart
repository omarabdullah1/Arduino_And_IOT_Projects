part of 'global_cubit.dart';

@immutable
abstract class GlobalState {}

class GlobalInitial extends GlobalState {}

class LoginLoadingState extends GlobalState {}

class LoginSuccessState extends GlobalState {
  final UserModel loginModel;

  LoginSuccessState(this.loginModel);
}

class LoginErrorState extends GlobalState {
  final String error;

  LoginErrorState(this.error);
}

class CreateUserLoadingState extends GlobalState {}

class CreateUserSuccessState extends GlobalState {}

class CreateUserErrorState extends GlobalState {
  final String error;

  CreateUserErrorState(this.error);
}

class RegisterLoadingState extends GlobalState {}

class RegisterSuccessState extends GlobalState {}

class RegisterErrorState extends GlobalState {
  final String error;

  RegisterErrorState(this.error);
}

class ChangePasswordVisibilityState extends GlobalState {}

class AppChangeLanguageState extends GlobalState {}

class LogoutState extends GlobalState {}

class AppChangeState extends GlobalState {}
