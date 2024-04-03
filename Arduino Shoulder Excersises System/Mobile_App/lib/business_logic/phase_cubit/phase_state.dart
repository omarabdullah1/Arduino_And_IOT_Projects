abstract class PhaseState {}

class PhaseInitial extends PhaseState {}

class ConnectToServerLoadingState extends PhaseState {}

class ConnectToServerSuccessState extends PhaseState {}

class DisconnectToServerSuccessState extends PhaseState {}

class ConnectToServerErrorState extends PhaseState {}

class SendToServerLoadingState extends PhaseState {}

class SendToServerSuccessState extends PhaseState {}

class SendToServerErrorState extends PhaseState {}

class AppChangeState extends PhaseState {}

class DisconnectToServerErrorState extends PhaseState {}
