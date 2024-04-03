import 'package:flutter/material.dart';
import 'package:shoulder_exercises/presentation/phase_one/phase_one_screen.dart';
import '../generated_data/screens.dart';
import '../phase_three/phase_three_screen.dart';
import '../phase_two/phase_two_screen.dart';
import '../screens/home/home.dart';
import '../screens/login/login_screen.dart';
import '../screens/register/register_screen.dart';
import '../screens/shared/splash_screen.dart';

class AppRouter {
  Route? onGenerateRoute(RouteSettings settings) {
    switch (settings.name) {
      case Screens.splashScreen:
        return MaterialPageRoute(builder: (_) => const SplashScreen());
      case Screens.loginScreen:
        return MaterialPageRoute(builder: (_) =>  const LoginScreen());
        case Screens.profileScreen:
        return MaterialPageRoute(builder: (_) =>  const HomeScreen());
        case Screens.registerScreen:
        return MaterialPageRoute(builder: (_) =>  const RegisterScreen());
        case Screens.phaseOneScreen:
        return MaterialPageRoute(builder: (_) =>   const PhaseOneScreen());
        case Screens.phaseTwoScreen:
        return MaterialPageRoute(builder: (_) =>   const PhaseTwoScreen());
        case Screens.phaseThreeScreen:
        return MaterialPageRoute(builder: (_) =>  const PhaseThreeScreen());
      default:
        return null;
    }
  }
}