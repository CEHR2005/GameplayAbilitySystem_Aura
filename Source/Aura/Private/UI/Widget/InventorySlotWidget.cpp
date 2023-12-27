// Copyright Druid Mechanics


#include "UI/Widget/InventorySlotWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

void UInventorySlotWidget::InitializeItem(const FItem& ItemData)
{
	if (NameText)
	{
		NameText->SetText(FText::FromString(ItemData.Name));
	}

	if (DescriptionText)
	{
		DescriptionText->SetText(FText::FromString(ItemData.Description));
	}

	if (CostText)
	{
		CostText->SetText(FText::AsNumber(ItemData.Cost));
	}

	CurrentItem = ItemData;

	if (BuyButton)
	{
		// BuyButton->OnClicked.AddDynamic(this, &UShopItemWidget::BuyButtonClicked);
	}
}
