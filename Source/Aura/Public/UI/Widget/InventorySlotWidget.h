// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "Actor/Inventory.h"
#include "UI/Widget/AuraUserWidget.h"
#include "InventorySlotWidget.generated.h"

class UTextBlock;
class UButton;
/**
 * 
 */
UCLASS()
class AURA_API UInventorySlotWidget : public UAuraUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void InitializeItem(const FItem& ItemData);
	
	UPROPERTY(BlueprintReadOnly, Category = "Item")
	FItem CurrentItem;
protected:


	bool HasItem;
	UPROPERTY(meta = (BindWidget))
	UButton* BuyButton;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* NameText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DescriptionText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CostText;
};
