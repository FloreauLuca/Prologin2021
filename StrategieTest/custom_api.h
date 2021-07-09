#pragma once
#include "api.hh"

#include <iostream>

void Log(std::string msg)
{
	std::cout << msg << std::endl;
}

void CheckError(erreur error, const char* file, int line, const char* func)
{
	if (error == OK) return;
	std::cout << "[" << file << " l." << line << " f." << func << "] ";
	switch (error)
	{
	case POSITION_INVALIDE:
		std::cout << "POSITION_INVALIDE" << std::endl;
		break;
	case POSITION_OBSTACLE:
		std::cout << "POSITION_OBSTACLE" << std::endl;
		break;
	case MAUVAIS_NOMBRE:
		std::cout << "MAUVAIS_NOMBRE" << std::endl;
		break;
	case DEPLACEMENT_HORS_LIMITES:
		std::cout << "DEPLACEMENT_HORS_LIMITES" << std::endl;
		break;
	case DIRECTION_INVALIDE:
		std::cout << "DIRECTION_INVALIDE" << std::endl;
		break;
	case MOUVEMENT_INVALIDE:
		std::cout << "MOUVEMENT_INVALIDE" << std::endl;
		break;
	case POSE_INVALIDE:
		std::cout << "POSE_INVALIDE" << std::endl;
		break;
	case ID_PANDA_INVALIDE:
		std::cout << "ID_PANDA_INVALIDE" << std::endl;
		break;
	case ACTION_DEJA_EFFECTUEE:
		std::cout << "ACTION_DEJA_EFFECTUEE" << std::endl;
		break;
	case DRAPEAU_INVALIDE:
		std::cout << "DRAPEAU_INVALIDE" << std::endl;
		break;
	case DEPLACEMENT_EN_ARRIERE:
		std::cout << "DEPLACEMENT_EN_ARRIERE" << std::endl;
		break;
	default:
		std::cout << "UNKNOWN" << std::endl;
	}
}

#define CheckErr( error ) CheckError( error, __FILE__, __LINE__, __FUNCTION__ )
