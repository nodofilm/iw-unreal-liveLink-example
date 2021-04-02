// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NODOLiveLink/Private/NODOLiveLinkSourceFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNODOLiveLinkSourceFactory() {}
// Cross Module References
	NODOLIVELINK_API UClass* Z_Construct_UClass_UNODOLiveLinkSourceFactory_NoRegister();
	NODOLIVELINK_API UClass* Z_Construct_UClass_UNODOLiveLinkSourceFactory();
	LIVELINKINTERFACE_API UClass* Z_Construct_UClass_ULiveLinkSourceFactory();
	UPackage* Z_Construct_UPackage__Script_NODOLiveLink();
// End Cross Module References
	void UNODOLiveLinkSourceFactory::StaticRegisterNativesUNODOLiveLinkSourceFactory()
	{
	}
	UClass* Z_Construct_UClass_UNODOLiveLinkSourceFactory_NoRegister()
	{
		return UNODOLiveLinkSourceFactory::StaticClass();
	}
	struct Z_Construct_UClass_UNODOLiveLinkSourceFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNODOLiveLinkSourceFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ULiveLinkSourceFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_NODOLiveLink,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNODOLiveLinkSourceFactory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "NODOLiveLinkSourceFactory.h" },
		{ "ModuleRelativePath", "Private/NODOLiveLinkSourceFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNODOLiveLinkSourceFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNODOLiveLinkSourceFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UNODOLiveLinkSourceFactory_Statics::ClassParams = {
		&UNODOLiveLinkSourceFactory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UNODOLiveLinkSourceFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UNODOLiveLinkSourceFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UNODOLiveLinkSourceFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UNODOLiveLinkSourceFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UNODOLiveLinkSourceFactory, 1544579785);
	template<> NODOLIVELINK_API UClass* StaticClass<UNODOLiveLinkSourceFactory>()
	{
		return UNODOLiveLinkSourceFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNODOLiveLinkSourceFactory(Z_Construct_UClass_UNODOLiveLinkSourceFactory, &UNODOLiveLinkSourceFactory::StaticClass, TEXT("/Script/NODOLiveLink"), TEXT("UNODOLiveLinkSourceFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNODOLiveLinkSourceFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
