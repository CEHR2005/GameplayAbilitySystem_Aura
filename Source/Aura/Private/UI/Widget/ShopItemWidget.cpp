// Copyright Druid Mechanics


#include "UI/Widget/ShopItemWidget.h"

void UShopItemWidget::InitializeItem(const FItem& ItemData)
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
		BuyButton->OnClicked.AddDynamic(this, &UShopItemWidget::BuyButtonClicked);
	}
}

void UShopItemWidget::BuyButtonClicked()
{
	OnBuyButtonClicked(); 
}
