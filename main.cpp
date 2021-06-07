#include <iostream>
#include <map>

#include "QuadroCopter.h"

int main()
{
	WayPoint wp_01("Stadt Stuttgart, Schnellzentrum Schlossplatz", 48.778555879487776, 9.180653355900166);
	WayPoint wp_02("Schwanenapotheke", 48.77468354911471, 9.179642427064902);
	WayPoint wp_03("Stadt Stuttgart, Schnelltestzentrum Hohe Strasse", 48.777323361696816, 9.169995484735308);
	WayPoint wp_04("Charlotten-Apotheke", 48.77433969698046, 9.186067454053777);
	WayPoint wp_05("Coronastation Koenigsbau-Passagen", 48.77956211190766, 9.177957371240943);
	WayPoint wp_06("Europa Apotheke", 48.773757129065956, 9.175048796383347);
	WayPoint wp_07("Internationale Apotheke", 48.77432626184128, 9.174144911724058);
	WayPoint wp_08("NK Medical Services GmbH - Testzentrum Schillerplatz/Schlossplatz", 48.77763755204808, 9.178668069394567);
	WayPoint wp_09("Schnelltestzentrum Olgaeck des Emma64 Mobiler Pflege-und Sozialdienst", 48.774082550637985, 9.187092284735183);
	WayPoint wp_10("Zahnarztpraxis Dr. Hendrik Putze", 48.771013827025186, 9.1754785405592);
	WayPoint wp_11("15minutentest.de (Testzentrum Dorotheenquartier)", 48.77561408760594, 9.17996766939451);
	WayPoint wp_12("Airbrushtanning", 48.77292572437396, 9.187508198229622);
	WayPoint wp_13("Gesundhaus Apotheke im Milaneo", 48.7910940757532, 9.184606142406075);
	WayPoint wp_14("Privomed GmbH - Corona Buergertestzentrum", 48.77366210521173, 9.184395313570374);
	WayPoint wp_15("Medicare Schnelltestzentrum Stuttgart-Mitte", 48.775954086648234, 9.17710222706492);
	WayPoint wp_16("Zahnarztpraxis Dr. Michael Huss", 48.782050647561476, 9.181806584735433);
	WayPoint wp_17("Teststelle Kronenstrasse", 48.78422960176436, 9.175452813570661);
	WayPoint wp_18("Teststelle Bohnenviertel", 48.7738778098216, 9.18210560007598);

	std::map<int, WayPoint> deliveries;

	deliveries.emplace(std::make_pair(1, wp_01));
	deliveries.emplace(std::make_pair(2, wp_02));
	deliveries.emplace(std::make_pair(3, wp_03));
	deliveries.emplace(std::make_pair(4, wp_04));
	deliveries.emplace(std::make_pair(5, wp_05));
	deliveries.emplace(std::make_pair(6, wp_06));
	deliveries.emplace(std::make_pair(7, wp_07));
	deliveries.emplace(std::make_pair(8, wp_08));
	deliveries.emplace(std::make_pair(9, wp_09));
	deliveries.emplace(std::make_pair(10, wp_10));
	deliveries.emplace(std::make_pair(11, wp_11));
	deliveries.emplace(std::make_pair(12, wp_12));
	deliveries.emplace(std::make_pair(13, wp_13));
	deliveries.emplace(std::make_pair(14, wp_14));
	deliveries.emplace(std::make_pair(15, wp_15));
	deliveries.emplace(std::make_pair(16, wp_16));
	deliveries.emplace(std::make_pair(17, wp_17));
	deliveries.emplace(std::make_pair(18, wp_18));

	WayPoint hq("Head Quarter", 48.803368608966835, 9.222155055900785);

	QuadroCopter copter_01("QuadroCopter 01", hq, "Low Range Copter", 20);
	QuadroCopter copter_02("QuadroCopter 02", hq, "Wide Range Copter", 50);

	for (const auto& elem : deliveries)
	{
		copter_01.add(elem.second);
		copter_02.add(elem.second);
	}

	copter_01.print();
	copter_02.print();

	return 0;
}

[[maybe_unused]] int main_res()
{
	WayPoint wp_1;
	WayPoint wp_2("Punkt 1", 1.0, 2.0);

	std::cout << wp_1 << std::endl;
	std::cout << wp_2 << std::endl;

	auto* pContainer_1 = new WayPointContainer();
	pContainer_1->add(wp_1);
	pContainer_1->add(wp_2);

	auto* pContainer_2 = new WayPointContainer(*pContainer_1);
	auto* pContainer_3 = new WayPointContainer();
	*pContainer_3 = *pContainer_1;

	// �nderung am ersten Container (Original)
	(*pContainer_1)[0].name("Klaus");

	pContainer_1->print();
	pContainer_2->print();
	pContainer_3->print();

	delete pContainer_1;
	delete pContainer_2;
	delete pContainer_3;

	auto* pCopter_1 = new QuadroCopter("Flight_01", WayPoint("Nauheimer 83", 48.804034706808196, 9.223216927065636), "Fast Model", 20);

	pCopter_1->print();

	return 0;
}