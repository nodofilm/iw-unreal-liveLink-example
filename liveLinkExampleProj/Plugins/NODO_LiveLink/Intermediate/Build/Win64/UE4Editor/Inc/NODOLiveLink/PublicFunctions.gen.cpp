// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NODOLiveLink/Public/PublicFunctions.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePublicFunctions() {}
// Cross Module References
	NODOLIVELINK_API UClass* Z_Construct_UClass_UPublicFunctions_NoRegister();
	NODOLIVELINK_API UClass* Z_Construct_UClass_UPublicFunctions();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_NODOLiveLink();
// End Cross Module References
	DEFINE_FUNCTION(UPublicFunctions::execSetPositionMultiplier)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_mult);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPublicFunctions::SetPositionMultiplier(Z_Param_mult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPublicFunctions::execSetRotationMultiplier)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_mult);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPublicFunctions::SetRotationMultiplier(Z_Param_mult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPublicFunctions::execResetZeroRotation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UPublicFunctions::ResetZeroRotation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPublicFunctions::execResetZeroPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UPublicFunctions::ResetZeroPosition();
		P_NATIVE_END;
	}
	void UPublicFunctions::StaticRegisterNativesUPublicFunctions()
	{
		UClass* Class = UPublicFunctions::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ResetZeroPosition", &UPublicFunctions::execResetZeroPosition },
			{ "ResetZeroRotation", &UPublicFunctions::execResetZeroRotation },
			{ "SetPositionMultiplier", &UPublicFunctions::execSetPositionMultiplier },
			{ "SetRotationMultiplier", &UPublicFunctions::execSetRotationMultiplier },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPublicFunctions_ResetZeroPosition_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPublicFunctions_ResetZeroPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "NODO" },
		{ "ModuleRelativePath", "Public/PublicFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPublicFunctions_ResetZeroPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPublicFunctions, nullptr, "ResetZeroPosition", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPublicFunctions_ResetZeroPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPublicFunctions_ResetZeroPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPublicFunctions_ResetZeroPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPublicFunctions_ResetZeroPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPublicFunctions_ResetZeroRotation_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPublicFunctions_ResetZeroRotation_Statics::Function_MetaDataParams[] = {
		{ "Category", "NODO" },
		{ "ModuleRelativePath", "Public/PublicFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPublicFunctions_ResetZeroRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPublicFunctions, nullptr, "ResetZeroRotation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPublicFunctions_ResetZeroRotation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPublicFunctions_ResetZeroRotation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPublicFunctions_ResetZeroRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPublicFunctions_ResetZeroRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier_Statics
	{
		struct PublicFunctions_eventSetPositionMultiplier_Parms
		{
			float mult;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_mult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier_Statics::NewProp_mult = { "mult", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PublicFunctions_eventSetPositionMultiplier_Parms, mult), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier_Statics::NewProp_mult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier_Statics::Function_MetaDataParams[] = {
		{ "Category", "NODO" },
		{ "ModuleRelativePath", "Public/PublicFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPublicFunctions, nullptr, "SetPositionMultiplier", nullptr, nullptr, sizeof(PublicFunctions_eventSetPositionMultiplier_Parms), Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier_Statics
	{
		struct PublicFunctions_eventSetRotationMultiplier_Parms
		{
			float mult;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_mult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier_Statics::NewProp_mult = { "mult", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PublicFunctions_eventSetRotationMultiplier_Parms, mult), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier_Statics::NewProp_mult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier_Statics::Function_MetaDataParams[] = {
		{ "Category", "NODO" },
		{ "ModuleRelativePath", "Public/PublicFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPublicFunctions, nullptr, "SetRotationMultiplier", nullptr, nullptr, sizeof(PublicFunctions_eventSetRotationMultiplier_Parms), Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPublicFunctions_NoRegister()
	{
		return UPublicFunctions::StaticClass();
	}
	struct Z_Construct_UClass_UPublicFunctions_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPublicFunctions_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_NODOLiveLink,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPublicFunctions_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPublicFunctions_ResetZeroPosition, "ResetZeroPosition" }, // 3217460753
		{ &Z_Construct_UFunction_UPublicFunctions_ResetZeroRotation, "ResetZeroRotation" }, // 2970436023
		{ &Z_Construct_UFunction_UPublicFunctions_SetPositionMultiplier, "SetPositionMultiplier" }, // 1087762288
		{ &Z_Construct_UFunction_UPublicFunctions_SetRotationMultiplier, "SetRotationMultiplier" }, // 4093575531
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPublicFunctions_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "PublicFunctions.h" },
		{ "ModuleRelativePath", "Public/PublicFunctions.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPublicFunctions_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPublicFunctions>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPublicFunctions_Statics::ClassParams = {
		&UPublicFunctions::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPublicFunctions_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPublicFunctions_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPublicFunctions()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPublicFunctions_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPublicFunctions, 4053394580);
	template<> NODOLIVELINK_API UClass* StaticClass<UPublicFunctions>()
	{
		return UPublicFunctions::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPublicFunctions(Z_Construct_UClass_UPublicFunctions, &UPublicFunctions::StaticClass, TEXT("/Script/NODOLiveLink"), TEXT("UPublicFunctions"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPublicFunctions);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
