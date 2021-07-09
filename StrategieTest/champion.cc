#include "api.hh"
#include "custom_api.h"

#include <iostream>

/// Fonction appelée au début de la partie.
void partie_init()
{
    std::cout << "partie_init\n";
    std::cout << "my ID :" << moi() << std::endl;
    std::cout << "Pandas : ";
    std::vector<panda_info> pandas = liste_pandas();
    for (int i = 0; i < pandas.size(); ++i)
    {
        afficher_panda_info(pandas[i]);
    }
    std::cout << std::endl;
	
    std::cout << "Bebes : ";
    std::vector<bebe_info> bebes = liste_bebes();
    for (int i = 0; i < bebes.size(); ++i)
    {
        afficher_bebe_info(bebes[i]);
    }
    std::cout << std::endl;
}

/// Fonction appelée à chaque tour.
void jouer_tour()
{
    std::cout << "jouer_tour\n";
    std::cout << "Tour Info";
    afficher_tour_info(info_tour());
    std::cout << std::endl;
    panda_info currentPanda = info_panda(position_panda(moi(), info_tour().id_panda_joue));
    debug_afficher_drapeau(currentPanda.panda_pos, DRAPEAU_BLEU);
    afficher_panda_info(currentPanda);
    std::vector<position> neighbors = positions_adjacentes(currentPanda.panda_pos);
    for (int i = 0; i < neighbors.size(); ++i)
    {
        afficher_position(neighbors[i]);
        afficher_case_type(type_case(neighbors[i]));
        std::cout << std::endl;
    }

	
    // TODO
}

/// Fonction appelée à la fin de la partie.
void partie_fin()
{
    std::cout << "partie_fin\n";
    // TODO
}
