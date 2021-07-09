#include "api.hh"

#include <iostream>

bool hasMove = false;
bool hasBuild = false;

direction find_dir_to_pos(position from, position to)
{
    direction dir;

    if (from.x < to.x)
    {
        if (from.y < to.y)
        {
            dir = SUD_EST;
        }
        else if (from.y > to.y)
        {
            dir = NORD_EST;
        }
        else
        {
            dir = (direction)direction_entre_positions(from, { from.x + 1, from.y });
        }
    }
    else if (from.x > to.x)
    {
        if (from.y < to.y)
        {
            dir = SUD_OUEST;
        }
        else if (from.y > to.y)
        {
            dir = NORD_OUEST;
        }
        else
        {
            dir = (direction)direction_entre_positions(from, { from.x - 1, from.y });
        }
    }
    else
    {
        if (from.y < to.y)
        {
            dir = SUD;
        }
        else if (from.y > to.y)
        {
            dir = NORD;
        }
        else
        {
            dir = (direction)direction_entre_positions(from, from);
        }
    }

    return dir;
}

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
    hasMove = false;
    hasBuild = false;
    std::cout << "jouer_tour\n";
    std::cout << "Tour Info";
    afficher_tour_info(info_tour());
    std::cout << std::endl;
    panda_info currentPanda = info_panda(position_panda(moi(), info_tour().id_panda_joue));
    debug_afficher_drapeau(currentPanda.panda_pos, DRAPEAU_BLEU);
    afficher_panda_info(currentPanda);
    afficher_pont_type(info_pont(currentPanda.panda_pos));
    std::vector<position> neighbors = positions_adjacentes(currentPanda.panda_pos);
    for (int i = 0; i < neighbors.size(); ++i)
    {
        std::cout << std::endl;
        afficher_position(neighbors[i]);
        afficher_direction((direction)direction_entre_positions(currentPanda.panda_pos, neighbors[i]));
        afficher_case_type(type_case(neighbors[i]));
        std::cout << std::endl;
        if (type_case(neighbors[i]) == PONT && !hasMove)
        {
            afficher_pont_type(info_pont(neighbors[i]));
            if (info_pont(neighbors[i]).fin_pos == info_pont(currentPanda.panda_pos).debut_pos ||
                info_pont(neighbors[i]).debut_val == info_pont(currentPanda.panda_pos).debut_val)
            {
                erreur error = deplacer((direction)direction_entre_positions(currentPanda.panda_pos, neighbors[i]));
                afficher_erreur(error);
                if (error == OK)
                {
                    hasMove = true;
                    break;
                }
            }
        }
        else
            if (type_case(neighbors[i]) == LIBRE && !hasBuild)
            {
                //Try to pose a bridge
                std::vector<position> bridge_neighbor = positions_adjacentes(neighbors[i]);
                for (int j = 0; j < bridge_neighbor.size(); ++j)
                {
                    if (type_case(bridge_neighbor[i]) == LIBRE)
                    {
                        direction dir = (direction)direction_entre_positions(neighbors[i], bridge_neighbor[i]);
                        afficher_direction(dir);
                        erreur error = poser(neighbors[i], dir, info_pont(currentPanda.panda_pos).debut_val, info_pont(currentPanda.panda_pos).debut_val);
                        afficher_erreur(error);
                        if (error == OK)
                        {
                            hasBuild = true;
                            hasMove = false;
                            break;
                        }
                    }
                }
            }
    }


    // TODO
}

/// Fonction appelée à la fin de la partie.
void partie_fin()
{
    std::cout << "partie_fin\n";
    // TODO
}
