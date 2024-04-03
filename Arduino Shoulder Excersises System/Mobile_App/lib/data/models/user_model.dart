class UserModel {
  String? name;
  String? email;
  String? phone;
  String? uId;
  bool? isEmailVerified;


  UserModel({
    required this.name,
    required this.email,
    required this.phone,
    required this.uId,
    required this.isEmailVerified,


  });
  UserModel.fromJson(Map<String, dynamic> json) {
    name = json['name'];
    email = json['email'];
    phone = json['phone'];
    uId = json['uId'];
    isEmailVerified = json['isEmailVerified'];
  }
  Map<String, dynamic> toMap() {
    return {
      'name': name,
      'phone': phone,
      'email': email,
      'uId': uId,
      'isEmailVerified': isEmailVerified,
     };
  }
}