// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "Actor/Inventory.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "UI/Widget/AuraUserWidget.h"
#include "ShopItemWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UShopItemWidget : public UAuraUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void InitializeItem(const FItem& ItemData);

	UFUNCTION(BlueprintCallable)
	void BuyButtonClicked();

	UFUNCTION(BlueprintImplementableEvent, Category = "Shop")
	void OnBuyButtonClicked();

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
