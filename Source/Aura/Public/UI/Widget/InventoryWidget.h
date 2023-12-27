// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "UI/Widget/AuraUserWidget.h"
#include "InventoryWidget.generated.h"

class UTextBlock;
class UButton;
class UInventorySlotWidget;
class UUniformGridPanel;
/**
 * 
 */
UCLASS()
class AURA_API UInventoryWidget : public UAuraUserWidget
{
	GENERATED_BODY()
	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* InventoryGridPanel;
	
	UPROPERTY(EditDefaultsOnly, Category = "Shop")
	TSubclassOf<UInventorySlotWidget> InventorySlotWidgetClass;
	
	UFUNCTION(BlueprintCallable)
	void UpdateInventory();

};
