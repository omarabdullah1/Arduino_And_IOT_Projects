// File generated by FlutterFire CLI.
// ignore_for_file: lines_longer_than_80_chars, avoid_classes_with_only_static_members
import 'package:firebase_core/firebase_core.dart' show FirebaseOptions;
import 'package:flutter/foundation.dart'
    show defaultTargetPlatform, kIsWeb, TargetPlatform;

/// Default [FirebaseOptions] for use with your Firebase apps.
///
/// Example:
/// ```dart
/// import 'firebase_options.dart';
/// // ...
/// await Firebase.initializeApp(
///   options: DefaultFirebaseOptions.currentPlatform,
/// );
/// ```
class DefaultFirebaseOptions {
  static FirebaseOptions get currentPlatform {
    if (kIsWeb) {
      return web;
    }
    switch (defaultTargetPlatform) {
      case TargetPlatform.android:
        return android;
      case TargetPlatform.iOS:
        return ios;
      case TargetPlatform.macOS:
        return macos;
      case TargetPlatform.windows:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for windows - '
          'you can reconfigure this by running the FlutterFire CLI again.',
        );
      case TargetPlatform.linux:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for linux - '
          'you can reconfigure this by running the FlutterFire CLI again.',
        );
      default:
        throw UnsupportedError(
          'DefaultFirebaseOptions are not supported for this platform.',
        );
    }
  }

  static const FirebaseOptions web = FirebaseOptions(
    apiKey: 'AIzaSyC48FtigcoXeZaZwC6kj9QbUPKmRrWWj3w',
    appId: '1:863316403391:web:3ecd0d0abac3d0f406120a',
    messagingSenderId: '863316403391',
    projectId: 'shoulderexercises-a2b2b',
    authDomain: 'shoulderexercises-a2b2b.firebaseapp.com',
    storageBucket: 'shoulderexercises-a2b2b.appspot.com',
    measurementId: 'G-01DJ5H3YVM',
  );

  static const FirebaseOptions android = FirebaseOptions(
    apiKey: 'AIzaSyCTf05bKr8aNAohE-5Y6PFDRfZ5OWm23SM',
    appId: '1:863316403391:android:eb85876453e9749c06120a',
    messagingSenderId: '863316403391',
    projectId: 'shoulderexercises-a2b2b',
    storageBucket: 'shoulderexercises-a2b2b.appspot.com',
  );

  static const FirebaseOptions ios = FirebaseOptions(
    apiKey: 'AIzaSyB0cFy9QU-1CjIKZ-bgWjD1T1kxUSqsoBo',
    appId: '1:863316403391:ios:b5df6a9a0d82758b06120a',
    messagingSenderId: '863316403391',
    projectId: 'shoulderexercises-a2b2b',
    storageBucket: 'shoulderexercises-a2b2b.appspot.com',
    iosBundleId: 'com.example.shoulderExercies',
  );

  static const FirebaseOptions macos = FirebaseOptions(
    apiKey: 'AIzaSyB0cFy9QU-1CjIKZ-bgWjD1T1kxUSqsoBo',
    appId: '1:863316403391:ios:a58f5f695a7df56206120a',
    messagingSenderId: '863316403391',
    projectId: 'shoulderexercises-a2b2b',
    storageBucket: 'shoulderexercises-a2b2b.appspot.com',
    iosBundleId: 'com.example.shoulderExercies.RunnerTests',
  );
}