#include "Weapon.h"


Weapon::Weapon()
{
	// Weapon identity
	wpnName_ = "Basic Rifle";
	wpnBase_ = WeaponBase::Rifle;

	// Weapon stats
	dmg_ = 0;
	armP_ = 0;
	wt_ = 0;
	magCap_ = 30;
	frMode_ = { FireMode::Semi};
	wpnRelCo_ = 1;
	curMag_ = 30;

	RecalculateStats();
}

// Weapon Identity Getters
std::string Weapon::GetName() const
{
	return wpnName_;
}

WeaponBase Weapon::GetBase() const
{
	return wpnBase_;
}

// Weapon Stat Getters
int Weapon::GetDamage() const
{
	return dmg_;
}

int Weapon::GetArmorPen() const
{
	return armP_;
}

int Weapon::GetAccuracy() const
{
	return acc_;
}

int Weapon::GetWeight() const
{
	return wt_;
}

int Weapon::GetMagCap() const
{
	return magCap_;
}

int Weapon::GetReloadCost() const
{
	return wpnRelCo_;
}

int Weapon::GetCurrentMag() const
{
	return curMag_;
}

void Weapon::SetWpnName(std::string newWpnName_)
{
	wpnName_ = newWpnName_;
}

void Weapon::SetWpnBase(WeaponBase newBase_)
{
	wpnBase_ = newBase_;

	RecalculateStats();
}

// Weapon Part Setters
void Weapon::SetBarrel(Barrel newBarrel_)
{
	wpnBarrel_ = newBarrel_;

	RecalculateStats();
}

void Weapon::SetCaliber(Caliber newCaliber_)
{
	wpnCaliber_ = newCaliber_;

	RecalculateStats();
}

void Weapon::SetSight(Sight newSight_)
{
	wpnSight_ = newSight_;

	RecalculateStats();
}

void Weapon::SetMuzzle(Muzzle newMuzzle_)
{
	wpnMuzzle_ = newMuzzle_;

	RecalculateStats();
}

void Weapon::SetStock(Stock newStock_)
{
	wpnStock_ = newStock_;

	RecalculateStats();
}

void Weapon::SetFireSelector(FireSelector newFireSelector_)
{
	wpnFireSelector_ = newFireSelector_;

	RecalculateStats();
}

void Weapon::SetMagazine(Magazine newMagazine_)
{
	wpnMagazine_ = newMagazine_;

	RecalculateStats();
}

// Weapon functions
void Weapon::RecalculateStats()
{

	// Weapon Base here, Starting accuracy threshold
	switch (wpnBase_)
	{
	case WeaponBase::Pistol:
		acc_ = 55;
		break;

	case WeaponBase::Rifle:
		acc_ = 100;
		break;

	}

	// CompactSMG, SMG, CompactCarbine, Carbine, Rifle, LongRifle
	switch (wpnBarrel_)
	{
	case Barrel::CompactSMG:
		dmg_ += 5;
		acc_ -= 5;
		armP_ += 0;
		wt_ += 1;
		break;

	case Barrel::SMG:
		dmg_ += 5;
		acc_ -= 8;
		armP_ += 1;
		wt_ += 1;
		break;

	case Barrel::CompactCarbine:
		dmg_ += 10;
		acc_ -= 10;
		armP_ += 5;
		wt_ += 2;
		break;

	case Barrel::Carbine:
		dmg_ += 10;
		acc_ -= 15;
		armP_ += 2;
		wt_ += 2;
		break;

	case Barrel::Rifle:
		dmg_ += 10;
		acc_ -= 18;
		armP_ += 10;
		wt_ += 3;
		break;

	case Barrel::LongRifle:
		dmg_ += 15;
		acc_ -= 20;
		armP_ += 5;
		wt_ += 4;
		break;

	}

	// Caliber here
	switch (wpnCaliber_)
	{
	case Caliber::c9x19mm:
		dmg_ += 30;
		armP_ += 0;
		wt_ += 1;
		break;
	case Caliber::c45ACP:
		dmg_ += 35;
		armP_ += 0;
		wt_ += 1;
		break;
	case Caliber::c357:
		dmg_ += 40;
		armP_ += 5;
		wt_ += 1;
		break;
	case Caliber::c44:
		dmg_ += 45;
		armP_ += 10;
		wt_ += 2;
		break;
	case Caliber::c545x39:
		dmg_ += 30;
		armP_ += 20;
		wt_ += 2;
		break;
	case Caliber::c556x45:
		dmg_ += 35;
		armP_ += 30;
		wt_ += 2;
		break;
	case Caliber::c762x39:
		dmg_ += 25;
		armP_ += 45;
		wt_ += 2;
		break;
	case Caliber::c762x51:
		dmg_ += 30;
		armP_ += 50;
		wt_ += 3;
		break;
	}

	// Sight here                
	switch (wpnSight_)
	{
	case Sight::irons:
		acc_ -= 0;
		wt_ += 0;
		break;
	case Sight::reddot:
		acc_ -= 3;
		wt_ += 1;
		break;
	case Sight::magreddot:
		acc_ -= 5;
		wt_ += 2;
		break;
	case Sight::midrange:
		acc_ -= 7;
		wt_ += 3;
		break;
	case Sight::longrange:
		acc_ -= 10;
		wt_ += 4;
		break;
	}

	// Muzzle here
	switch (wpnMuzzle_)
	{
	case Muzzle::flashGuard:
		acc_ += 1;
		wt_ += 1;
		break;
	case Muzzle::compensator:
		acc_ -= 2;
		wt_ += 1;
		break;
	case Muzzle::booster:
		acc_ -= 3;
		wt_ += 2;
		break;
	case Muzzle::superessor:
		acc_ -= 5;
		wt_ += 3;
		break;
	case Muzzle::advsupressor:
		acc_ -= 6;
		wt_ += 4;
		break;
	}

	// Stock here
	switch (wpnStock_)
	{
	case Stock::noStock:
		acc_ += 5;
		wt_ -= 2;
		break;
	case Stock::CollapseStockClpsd:
		acc_ += 2;
		wt_ -= 1;
		break;
	case Stock::CollapseStockExtd:
		acc_ -= 3;
		wt_ += 1;
		break;
	case Stock::FullStock:
		acc_ += 5;
		wt_ += 3;
		break;
	case Stock::HeavyStock:
		acc_ -= 7;
		wt_ += 5;
		break;
	}

	// FireSelector here
	switch (wpnFireSelector_)
	{
	case FireSelector::Semi:
		frMode_ = { FireMode::Semi };
		break;
	case FireSelector::SemiBurst:
		frMode_ = { FireMode::Semi, FireMode::Burst };
		break;
	case FireSelector::SemiAuto:
		frMode_ = { FireMode::Semi, FireMode::Auto };
		break;
	case FireSelector::Navy:
		frMode_ = { FireMode::Semi, FireMode::Burst, FireMode::Auto };
		break;
	}

	// Magazine here
	switch (wpnMagazine_)
	{
	case Magazine::BreechLoaded:
		magCap_ = 1;
		wt_ -= 3;
		break;
	case Magazine::SmallMag:
		magCap_ = 20;
		wt_ += 2;
		break;
	case Magazine::MediumMag:
		magCap_ = 30;
		wt_ += 3;
		break;
	case Magazine::LargeMag:
		magCap_ = 50;
		wt_ += 5;
		break;
	case Magazine::SmallDrum:
		magCap_ = 60;
		wt_ += 6;
		break;
	case Magazine::Drum:
		magCap_ = 100;
		wt_ += 8;
		break;
	case Magazine::Belt:
		magCap_ = 250;
		wt_ += 10;
		break;
	}
}

void Weapon::SelectWpnBase()
{

	std::vector<std::string> options = { "Pistol", "Rifle", "Back"};

	while (true)
	{
		int choice = ui_.menuHandler("Weapon Base", options);

		switch (choice)
		{
		case 1:
			SetWpnBase(WeaponBase::Pistol);
			return;
		case 2:
			SetWpnBase(WeaponBase::Rifle);
			return;
		case 3:
			return;

		default:
			break;
		}
	}
}

void Weapon::SelectBarrel()
{

	std::vector<std::string> options = { "Compact SMG", "SMG", "Compact Carbine", "Carbine", "Rifle", "Long Rifle", "Back" };
	
	while (true)
	{
		int choice = ui_.menuHandler("             Barrel Type", options);

		switch (choice)
		{
		case 1:
			SetBarrel(Barrel::CompactSMG);
			return;

		case 2:
			SetBarrel(Barrel::SMG);
			return;

		case 3:
			SetBarrel(Barrel::CompactCarbine);
			return;

		case 4:
			SetBarrel(Barrel::Carbine);
			return;

		case 5:
			SetBarrel(Barrel::Rifle);
			return;

		case 6:
			SetBarrel(Barrel::LongRifle);
			return;

		case 7:
			return;

		default:
			break;
		}
	}
}

void Weapon::SelectCaliber()
{

	std::vector<std::string> options = { "9x19mm", ".45 ACP", ".357", ".44", "5.45x39mm", "5.56x45mm", "7.62x39mm", "7.62x51mm", "Back" };

	while (true)
	{
		int choice = ui_.menuHandler("             Caliber", options);

		switch (choice)
		{
		case 1:
			SetCaliber(Caliber::c9x19mm);
			return;

		case 2:
			SetCaliber(Caliber::c45ACP);
			return;

		case 3:
			SetCaliber(Caliber::c357);
			return;

		case 4:
			SetCaliber(Caliber::c44);
			return;

		case 5:
			SetCaliber(Caliber::c545x39);
			return;

		case 6:
			SetCaliber(Caliber::c556x45);
			return;

		case 7:
			SetCaliber(Caliber::c762x39);
			return;

		case 8:
			SetCaliber(Caliber::c762x51);
			return;

		case 9:
			return;

		default:
			break;
		}
	}
}

void Weapon::SelectSight()
{

	std::vector<std::string> options = { "Irons", "Red Dot", "Magnified Red Dot", "Mid Range Optic", "Long Range Optic", "Back" };

	while (true)
	{
		int choice = ui_.menuHandler("             Sight Type", options);

		switch (choice)
		{
		case 1:
			SetSight(Sight::irons);
			return;

		case 2:
			SetSight(Sight::reddot);
			return;

		case 3:
			SetSight(Sight::magreddot);
			return;

		case 4:
			SetSight(Sight::midrange);
			return;

		case 5:
			SetSight(Sight::longrange);
			return;

		case 6:
			return;

		default:
			break;
		}
	}
}

void Weapon::SelectMuzzle()
{

	std::vector<std::string> options = { "Flash Guard", "Compensator", "Booster", "Supressor", "Advanced Supressor", "Back" };

	while (true)
	{
		int choice = ui_.menuHandler("             Muzzle Type", options);

		switch (choice)
		{
		case 1:
			SetMuzzle(Muzzle::flashGuard);
			return;

		case 2:
			SetMuzzle(Muzzle::compensator);
			return;

		case 3:
			SetMuzzle(Muzzle::booster);
			return;

		case 4:
			SetMuzzle(Muzzle::superessor);
			return;

		case 5:
			SetMuzzle(Muzzle::advsupressor);
			return;

		case 6:
			return;

		default:
			break;
		}
	}
}

void Weapon::SelectStock()
{

	std::vector<std::string> options = { "No Stock", "Collapsable Stock (Collapsed)", "Collapsable Stock (Extended)", "Full Stock", "Heavy Stock", "Back" };

	while (true)
	{
		int choice = ui_.menuHandler("             Stock Type", options);

		switch (choice)
		{
		case 1:
			SetStock(Stock::noStock);
			return;

		case 2:
			SetStock(Stock::CollapseStockClpsd);
			return;

		case 3:
			SetStock(Stock::CollapseStockExtd);
			return;

		case 4:
			SetStock(Stock::FullStock);
			return;

		case 5:
			SetStock(Stock::HeavyStock);
			return;

		case 6:
			return;

		default:
			break;
		}
	}
}

void Weapon::SelectFireSelector()
{

	std::vector<std::string> options = { "Semi", "Semi/Burst", "Semi/Full Auto", "Navy (All)", "Back" };

	while (true)
	{
		int choice = ui_.menuHandler("             Fire Selector", options);

		switch (choice)
		{
		case 1:
			SetFireSelector(FireSelector::Semi);
			return;

		case 2:
			SetFireSelector(FireSelector::SemiBurst);
			return;

		case 3:
			SetFireSelector(FireSelector::SemiAuto);
			return;

		case 4:
			SetFireSelector(FireSelector::Navy);
			return;

		case 5:
			return;

		default:
			break;
		}
	}
}

void Weapon::SelectMagazine()
{

	std::vector<std::string> options = { "Breech Loaded", "Small Magazine", "Medium Magazine", "Large Magazine", "Small Drum", "Drum", "Belt Fed"};

	while (true)
	{
		int choice = ui_.menuHandler("           Magazine Type", options);

		switch (choice)
		{
		case 1:
			SetMagazine(Magazine::BreechLoaded);
			return;

		case 2:
			SetMagazine(Magazine::SmallMag);
			return;

		case 3:
			SetMagazine(Magazine::MediumMag);
			return;

		case 4:
			SetMagazine(Magazine::LargeMag);
			return;

		case 5:
			SetMagazine(Magazine::SmallDrum);
			return;

		case 6:
			SetMagazine(Magazine::Drum);
			return;

		case 7:
			SetMagazine(Magazine::Belt);

		case 8:
			return;

		default:
			break;
		}
	}
}

void Weapon::useBoolet()
{
	if (curMag_ > 0)
	{
		curMag_--;
	}
}

void Weapon::reload()
{
	curMag_ = magCap_;
}

std::vector<FireMode> Weapon::GetFireModes() const
{
	return frMode_;
}

bool Weapon::Customize()
{

	std::vector<std::string> options = 
	{ "Change Base", "Change Barrel", "Change caliber", "Change sight", "Change muzzle", "Change stock", "Change Fire Selector", "Change Magazine", "Change Name", "Confirm Changes", "Cancel"};

	while (true)
	{
		ui_.clearScreen();
		ui_.border();
		std::cout << "            Weapon Stats" << std::endl;
		ui_.border();
		int accPercent = 101 - acc_;

		std::cout << "Weapon: " << wpnName_ << std::endl;
		std::cout << "Damage: " << dmg_ << std::endl;
		std::cout << "Base Hit Chance: " << accPercent << "%" << std::endl;
		std::cout << "Armor Pen: " << armP_ << std::endl;
		std::cout << "Weight: " << wt_ << std::endl;
		std::cout << "Mag size: " << magCap_ << std::endl;
		std::cout << "Reload Cost: " << wpnRelCo_ << " AP" << std::endl;

		int choice = ui_.menuHandler("         Weapon Parts List", options);

		switch (choice)
		{
		case 1:
			// Base
			SelectWpnBase();
			break;
			
		case 2:
			// Barrel
			SelectBarrel();
			break;
			
		case 3:
			// Caliber
			SelectCaliber();
			break;
			
		case 4:
			// Sight
			SelectSight();
			break;
			
		case 5:
			// Muzzle
			SelectMuzzle();
			break;
			
		case 6:
			// stock
			SelectStock();
			break;
			
		case 7:
			// Fire Selector
			SelectFireSelector();
			break;
			
		case 8:
			// Magazine
			SelectMagazine();
			break;

		case 9:
			break;

		case 10:
			return true;

		case 11:
			return false;

		default:
			break;
		}
	}
}
