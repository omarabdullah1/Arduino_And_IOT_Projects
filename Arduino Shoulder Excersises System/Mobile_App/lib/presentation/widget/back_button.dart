import 'package:flutter/material.dart';

import '../styles/colors.dart';

class BackButtonWidget extends StatelessWidget {
  final double? height;
  final bool? direction;

  const BackButtonWidget({super.key, this.height, this.direction});

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(5.0),
      child: InkWell(
        onTap: () {
          print('object');
          Navigator.pop(context);
        },
        child: Container(
          height: height ?? 40.0,
          width: height ?? 40.0,
          decoration: BoxDecoration(
            color: AppColor.white,
            borderRadius: BorderRadius.circular(25.0),
            // boxShadow: <BoxShadow>[
            //   BoxShadow(
            //     color: AppColor.black.withOpacity(0.4),
            //     blurRadius: 35,
            //     offset: const Offset(0, 0),
            //   ),
            // ],
          ),
          child: Center(
            child: Icon(
              direction != null
                  ? direction==true
                      ? Icons.arrow_back_ios_new
                      : Icons.arrow_forward_ios
                  : Icons.arrow_back_ios_new,
              size: 20.0,
              color: AppColor.primary,
            ),
          ),
        ),
      ),
    );
  }
}
