// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"

#include "LiveLinkRetargetAsset.generated.h"

struct FLiveLinkSubjectFrame;
struct FCompactPose;
struct FBlendedCurve;

// Base class for retargeting live link data. 
UCLASS(Abstract)
class LIVELINK_API ULiveLinkRetargetAsset : public UObject
{
	GENERATED_UCLASS_BODY()

	// Builds curve data into OutCurve from the supplied live link frame
	void BuildCurveData(const FLiveLinkSubjectFrame& InFrame, const FCompactPose& InPose, FBlendedCurve& OutCurve) const;

	// Called once when the retargeter is created 
	virtual void Initialize() {}

	// Build OutPose and OutCurve from the supplied InFrame.
	virtual void BuildPoseForSubject(float DeltaTime, const FLiveLinkSubjectFrame& InFrame, FCompactPose& OutPose, FBlendedCurve& OutCurve) PURE_VIRTUAL(ULiveLinkRetargetAsset::BuildPoseForSubject, );
};
