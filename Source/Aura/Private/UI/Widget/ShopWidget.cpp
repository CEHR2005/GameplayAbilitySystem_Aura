// Copyright Druid Mechanics


#include "UI/Widget/ShopWidget.h"

#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "UI/Widget/ShopItemWidget.h"

class UUniformGridSlot;

void UShopWidget::LoadItems()
{
	if (!ItemsDataTable || !ShopGridPanel || !ShopItemWidgetClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("ShopWidget: DataTable, GridPanel or ItemWidgetClass is not set."));
		return;
	}

	TArray<FItem*> AllItems;
	ItemsDataTable->GetAllRows<FItem>(TEXT("CONTEXT STRING"), AllItems);

	const int32 NumColumns = 4; 
	int32 Row = 0;
	int32 Column = 0;

	for (FItem* ItemData : AllItems)
	{
		if (ItemData != nullptr)
		{
			UShopItemWidget* ItemWidget = CreateWidget<UShopItemWidget>(this, ShopItemWidgetClass);
			if (ItemWidget)
			{
				ItemWidget->InitializeItem(*ItemData);
				UUniformGridSlot* GridSlot = ShopGridPanel->AddChildToUniformGrid(ItemWidget);
				GridSlot->SetRow(Row);
				GridSlot->SetColumn(Column);

				if (++Column >= NumColumns)
				{
					Column = 0;
					++Row;
				}
			}
		}
	}
}
