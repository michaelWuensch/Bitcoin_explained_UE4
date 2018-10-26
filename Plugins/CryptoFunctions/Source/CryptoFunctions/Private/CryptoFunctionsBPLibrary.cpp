// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CryptoFunctionsBPLibrary.h"
#include "CryptoFunctions.h"

UCryptoFunctionsBPLibrary::UCryptoFunctionsBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


TArray<uint8> UCryptoFunctionsBPLibrary::RIPEMD160(const TArray<uint8>& ByteArray)
{
	const int32 Length = 0x7FFFFFFF;
	uint8_t Input[32];
	for (int i = 0; 31; i++) {
		Input[i] = ByteArray[i];
	}
	
	uint8_t ResultHash[20]; // holds the intermediate RIPMD160 hash computations
	
	computeRIPEMD160(Input,32,ResultHash);

	TArray<uint8> result;
	for (int i = 0; 20; i++) {
		result[i] = ResultHash[i];
	}

	
	return result;
}


FString UCryptoFunctionsBPLibrary::BigIntegerAdd(FString Int1, FString Int2)
{
	std::string Int1String(TCHAR_TO_UTF8(*Int1));  //convert FString to String
	std::string Int2String(TCHAR_TO_UTF8(*Int2));
	BigInteger a = stringToBigInteger(Int1String); //convert String to BigInteger
	BigInteger b = stringToBigInteger(Int2String);
	BigInteger r = a+b;
	std::string resultString = bigIntegerToString(r);  //convert result BigInteger to String
	FString result(resultString.c_str());
	return result;
}

FString UCryptoFunctionsBPLibrary::BigIntegerSubtract(FString Int1, FString Int2)
{
	std::string Int1String(TCHAR_TO_UTF8(*Int1));  //convert FString to String
	std::string Int2String(TCHAR_TO_UTF8(*Int2));
	BigInteger a = stringToBigInteger(Int1String); //convert String to BigInteger
	BigInteger b = stringToBigInteger(Int2String);
	BigInteger r = a - b;
	std::string resultString = bigIntegerToString(r);  //convert result BigInteger to String
	FString result(resultString.c_str());
	return result;
}

FString UCryptoFunctionsBPLibrary::BigIntegerMultiply(FString Int1, FString Int2)
{
	std::string Int1String(TCHAR_TO_UTF8(*Int1));  //convert FString to String
	std::string Int2String(TCHAR_TO_UTF8(*Int2));
	BigInteger a = stringToBigInteger(Int1String); //convert String to BigInteger
	BigInteger b = stringToBigInteger(Int2String);
	BigInteger r = a * b;
	std::string resultString = bigIntegerToString(r);  //convert result BigInteger to String
	FString result(resultString.c_str());
	return result;
}

FString UCryptoFunctionsBPLibrary::BigIntegerDivide(FString Int1, FString Int2)
{
	std::string Int1String(TCHAR_TO_UTF8(*Int1));  //convert FString to String
	std::string Int2String(TCHAR_TO_UTF8(*Int2));
	BigInteger a = stringToBigInteger(Int1String); //convert String to BigInteger
	BigInteger b = stringToBigInteger(Int2String);
	BigInteger r = a / b;
	std::string resultString = bigIntegerToString(r);  //convert result BigInteger to String
	FString result(resultString.c_str());
	return result;
}

FString UCryptoFunctionsBPLibrary::BigIntegerPower(FString Base, FString Exp)
{
	std::string Int1String(TCHAR_TO_UTF8(*Base));  //convert FString to String
	std::string Int2String(TCHAR_TO_UTF8(*Exp));
	BigInteger a = stringToBigInteger(Int1String); //convert String to BigInteger
	BigInteger b = stringToBigInteger(Int2String);
	int maxPower = b.toInt();

	BigInteger x(1);
	if (maxPower > 0){
		for (int power = 0; power <= maxPower-1; power++) {
			x *= a; // A BigInteger assignment operator
		}
	}

	std::string resultString = bigIntegerToString(x);  //convert result BigInteger to String
	FString result(resultString.c_str());
	return result;
}

FString UCryptoFunctionsBPLibrary::BigIntegerModulo(FString Int1, FString Int2)
{
	std::string Int1String(TCHAR_TO_UTF8(*Int1));  //convert FString to String
	std::string Int2String(TCHAR_TO_UTF8(*Int2));
	BigInteger a = stringToBigInteger(Int1String); //convert String to BigInteger
	BigInteger b = stringToBigInteger(Int2String);
	BigInteger r = a % b;
	std::string resultString = bigIntegerToString(r);  //convert result BigInteger to String
	FString result(resultString.c_str());
	return result;
}

bool UCryptoFunctionsBPLibrary::BigIntegerLess(FString Int1, FString Int2)
{
	std::string Int1String(TCHAR_TO_UTF8(*Int1));  //convert FString to String
	std::string Int2String(TCHAR_TO_UTF8(*Int2));
	BigInteger a = stringToBigInteger(Int1String); //convert String to BigInteger
	BigInteger b = stringToBigInteger(Int2String);
	bool result = a < b;
	return result;
}

bool UCryptoFunctionsBPLibrary::BigIntegerGreater(FString Int1, FString Int2)
{
	std::string Int1String(TCHAR_TO_UTF8(*Int1));  //convert FString to String
	std::string Int2String(TCHAR_TO_UTF8(*Int2));
	BigInteger a = stringToBigInteger(Int1String); //convert String to BigInteger
	BigInteger b = stringToBigInteger(Int2String);
	bool result = a > b;
	return result;
}

bool UCryptoFunctionsBPLibrary::BigIntegerEqual(FString Int1, FString Int2)
{
	std::string Int1String(TCHAR_TO_UTF8(*Int1));  //convert FString to String
	std::string Int2String(TCHAR_TO_UTF8(*Int2));
	BigInteger a = stringToBigInteger(Int1String); //convert String to BigInteger
	BigInteger b = stringToBigInteger(Int2String);
	bool result = a == b;
	return result;
}

bool UCryptoFunctionsBPLibrary::BigIntegerLessEqual(FString Int1, FString Int2)
{
	std::string Int1String(TCHAR_TO_UTF8(*Int1));  //convert FString to String
	std::string Int2String(TCHAR_TO_UTF8(*Int2));
	BigInteger a = stringToBigInteger(Int1String); //convert String to BigInteger
	BigInteger b = stringToBigInteger(Int2String);
	bool result = a <= b;
	return result;
}

bool UCryptoFunctionsBPLibrary::BigIntegerGreaterEqual(FString Int1, FString Int2)
{
	std::string Int1String(TCHAR_TO_UTF8(*Int1));  //convert FString to String
	std::string Int2String(TCHAR_TO_UTF8(*Int2));
	BigInteger a = stringToBigInteger(Int1String); //convert String to BigInteger
	BigInteger b = stringToBigInteger(Int2String);
	bool result = a >= b;
	return result;
}
