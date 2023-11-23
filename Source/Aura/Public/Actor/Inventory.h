// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory.generated.h"

USTRUCT(BlueprintType)
struct FItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Cost;
	
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

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FItem> Items;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem AddItem(const FItem& NewItem);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(const FItem& Item);
};
