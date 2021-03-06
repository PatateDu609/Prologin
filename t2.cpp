
#include <iostream>
#include <vector>
#include <cmath>

struct lieu {
    int id;
    int decalage;
};

struct etape {
    int voyageur;
    int destination;
};

int decalage(std::vector<lieu> const& lieux, int id) {
	for(size_t i = 0; i < lieux.size(); i++) {
		if(lieux.at(i).id == id) return lieux.at(i).decalage;
	}
}

void meli_melo_temporel0(std::vector<lieu> const& lieux, int n, std::vector<etape> const& etapes, int v) {
    int jetlag, haruhi = 0, joseph = 0, lH, lJ;
    for(int i = 0; i < v; i++) {
    	if(1 == etapes.at(i).voyageur) if(haruhi != etapes.at(i).destination) haruhi = etapes.at(i).destination;
    	if(2 == etapes.at(i).voyageur) if(joseph != etapes.at(i).destination) joseph = etapes.at(i).destination;
    	
    	lJ = decalage(lieux, joseph);
    	lH = decalage(lieux, haruhi);
    	
    	jetlag = std::abs(lJ) + std::abs(lH);
    	
    	std::cout << jetlag << std::endl;
    }
}

int main() {
    int destination, voyageur, v, decalage, id, n;
    std::cin >> n;
    std::vector<lieu> liste_p = std::vector<lieu>( n );
    for (int i = 0; i < n; i++)
    {
        std::cin >> id >> decalage;
        lieu lieux_i = lieu();
            lieux_i.id = id;
            lieux_i.decalage = decalage;
        liste_p.at(i) = lieux_i;
    }
    std::cin >> v;
    std::vector<etape> liste_e = std::vector<etape>( v );
    for (int j = 0; j < v; j++)
    {
        std::cin >> voyageur >> destination;
        etape etape_i = etape();
            etape_i.voyageur = voyageur;
            etape_i.destination = destination;
        liste_e.at(j) = etape_i;
    }
    meli_melo_temporel0(liste_p, n, liste_e, v);
    
    return 0;
}


