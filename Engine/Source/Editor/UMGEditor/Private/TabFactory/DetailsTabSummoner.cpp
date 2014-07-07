// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "UMGEditorPrivatePCH.h"

#include "DetailsTabSummoner.h"
#include "SWidgetDetailsView.h"

#define LOCTEXT_NAMESPACE "UMG"

const FName FDetailsTabSummoner::TabID(TEXT("WidgetDetails"));

FDetailsTabSummoner::FDetailsTabSummoner(TSharedPtr<class FWidgetBlueprintEditor> InBlueprintEditor)
		: FWorkflowTabFactory(TabID, InBlueprintEditor)
		, BlueprintEditor(InBlueprintEditor)
{
	TabLabel = LOCTEXT("WidgetDetails_TabLabel", "Details");
	//TabIcon = FEditorStyle::GetBrush("Kismet.Tabs.Components");

	bIsSingleton = true;

	ViewMenuDescription = LOCTEXT("WidgetDetails_ViewMenu_Desc", "Details");
	ViewMenuTooltip = LOCTEXT("WidgetDetails_ViewMenu_ToolTip", "Show the Details");
}

TSharedRef<SWidget> FDetailsTabSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	TSharedPtr<FWidgetBlueprintEditor> BlueprintEditorPtr = StaticCastSharedPtr<FWidgetBlueprintEditor>(BlueprintEditor.Pin());

	return SNew(STutorialWrapper, TEXT("Details"))
		[
			SNew(SWidgetDetailsView, BlueprintEditorPtr)
		];
}

#undef LOCTEXT_NAMESPACE 
