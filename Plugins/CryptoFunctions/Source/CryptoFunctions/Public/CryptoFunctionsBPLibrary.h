// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BigIntegerLibrary.hh"
#include "RIPEMD160.h"
#include "CryptoFunctionsBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UCryptoFunctionsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintPure, meta = (DisplayName = "RIPEMD-160", Keywords = "ripemd 160 hash"), Category = "Crypto Functions|Hashes")
	static TArray<uint8> RIPEMD160(const TArray<uint8>& ByteArray);
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Big Integer + Big Integer", CompactNodeTitle = "BigInt +", Keywords = "big integer add int +"), Category = "Crypto Functions|Big Integer|Math")
	static FString BigIntegerAdd(FString Int1, FString Int2);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Big Integer - Big Integer", CompactNodeTitle = "BigInt -", Keywords = "big integer subtract int -"), Category = "Crypto Functions|Big Integer|Math")
	static FString BigIntegerSubtract(FString Int1, FString Int2);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Big Integer * Big Integer", CompactNodeTitle = "BigInt *", Keywords = "big integer multiply int *"), Category = "Crypto Functions|Big Integer|Math")
	static FString BigIntegerMultiply(FString Int1, FString Int2);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Big Integer / Big Integer", CompactNodeTitle = "BigInt /", Keywords = "big integer divide int /"), Category = "Crypto Functions|Big Integer|Math")
	static FString BigIntegerDivide(FString Int1, FString Int2);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Big Integer % Big Integer", CompactNodeTitle = "BigInt %", Keywords = "big integer modulo int %"), Category = "Crypto Functions|Big Integer|Math")
	static FString BigIntegerModulo(FString Int1, FString Int2);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Power(Big Integer)", CompactNodeTitle = "Pow(BigInt)", Keywords = "big integer power int"), Category = "Crypto Functions|Big Integer|Math")
	static FString BigIntegerPower(FString Base, FString Exp);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "BigInteger < BigInteger", CompactNodeTitle = "BigInt <", Keywords = "big integer less int <"), Category = "Crypto Functions|Big Integer|Compare")
	static bool BigIntegerLess(FString Int1, FString Int2);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "BigInteger > BigInteger", CompactNodeTitle = "BigInt >", Keywords = "big integer greater int >"), Category = "Crypto Functions|Big Integer|Compare")
	static bool BigIntegerGreater(FString Int1, FString Int2);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal(BigInteger)", CompactNodeTitle = "BigInt ==", Keywords = "big integer greater int >"), Category = "Crypto Functions|Big Integer|Compare")
	static bool BigIntegerEqual(FString Int1, FString Int2);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "BigInteger <= BigInteger", CompactNodeTitle = "BigInt <=", Keywords = "big integer less equal int > ="), Category = "Crypto Functions|Big Integer|Compare")
	static bool BigIntegerLessEqual(FString Int1, FString Int2);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "BigInteger >= BigInteger", CompactNodeTitle = "BigInt >=", Keywords = "big integer greater equal int > ="), Category = "Crypto Functions|Big Integer|Compare")
	static bool BigIntegerGreaterEqual(FString Int1, FString Int2);

};
