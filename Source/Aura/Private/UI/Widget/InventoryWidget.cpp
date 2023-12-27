// Copyright Druid Mechanics


#include "UI/Widget/InventoryWidget.h"

#include "Character/AuraCharacter.h"
#include "UI/Widget/InventorySlotWidget.h"
#include "Actor/Inventory.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"

struct FItem;

void UInventoryWidget::UpdateInventory()
{
	APlayerController* PlayerController = GetOwningPlayer();
	UE_LOG(LogTemp, Warning, TEXT("Trying to get player controller"));
	InventoryGridPanel->ClearChildren();
	if (PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller found"));
		AAuraCharacter* AuraCharacter = Cast<AAuraCharacter>(PlayerController->GetPawn());
		if (AuraCharacter && AuraCharacter->InventoryComponent)
		{
			UE_LOG(LogTemp, Warning, TEXT("AuraCharacter and InventoryComponent found"))
			AInventory* Inventory = AuraCharacter->InventoryComponent;
			TArray<FItem> InventoryItems = Inventory->Items;
			const int32 NumColumns = 3; 
			int32 Row = 0;
			int32 Column = 0;
			for (const FItem& Item : InventoryItems)
			{
					if (!InventorySlotWidgetClass)
					{
						UE_LOG(LogTemp, Error, TEXT("InventorySlotWidgetClass is null"));
						return;
					}

					UInventorySlotWidget* ItemWidget = CreateWidget<UInventorySlotWidget>(this, InventorySlotWidgetClass);
					if (ItemWidget)
					{
						ItemWidget->InitializeItem(Item);
						ItemWidget->Index = Row * NumColumns + Column;
						UUniformGridSlot* GridSlot = InventoryGridPanel->AddChildToUniformGrid(ItemWidget);
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
}
