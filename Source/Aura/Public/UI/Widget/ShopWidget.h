// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "ShopItemWidget.h"
#include "UI/Widget/AuraUserWidget.h"
#include "ShopWidget.generated.h"

class UUniformGridPanel;
struct FItem;
/**
 * 
 */
UCLASS()
class AURA_API UShopWidget : public UAuraUserWidget
{
	GENERATED_BODY()

public:
// Create array of items
	TArray<FItem> Items;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shop")
	UDataTable* ItemsDataTable;
	
	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* ShopGridPanel;
	
	UPROPERTY(EditDefaultsOnly, Category = "Shop")
	TSubclassOf<UShopItemWidget> ShopItemWidgetClass;
	UFUNCTION(BlueprintCallable)
	void LoadItems();
};
