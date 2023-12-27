// Copyright Druid Mechanics


#include "Actor/Inventory.h"

AInventory::AInventory()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AInventory::BeginPlay()
{
	Super::BeginPlay();
	
}



FItem AInventory::AddItem(const FItem& NewItem)
{
	Items.Add(NewItem);

	UE_LOG(LogTemp, Warning, TEXT("Item %s added to inventory."), *NewItem.Name);
	OnInventoryUpdated.Broadcast();
	return NewItem;

}

void AInventory::RemoveItem(const FItem& Item)
{
	Items.Remove(Item);
	OnInventoryUpdated.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Item %s removed from inventory."), *Item.Name);

}



