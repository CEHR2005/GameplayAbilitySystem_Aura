// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

USTRUCT(BlueprintType)
struct FItem: public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Cost = 0;
	
	bool operator==(const FItem& Other) const
	{
		return Name == Other.Name; // You can compare additional fields if needed
	}
};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AURA_API AInventory : public AActor
{
	GENERATED_BODY()
	
public:	
	AInventory();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FItem> Items;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem AddItem(const FItem& NewItem);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(const FItem& Item);
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItemByIndex(int32 Index);
	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated;
protected:
	virtual void BeginPlay() override;

private:

};
