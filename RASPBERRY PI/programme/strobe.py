import afficheur

def strobe(v,N,matrice):
    for i in range(N):
        afficheur.affiche(v,matrice)

        for j in range(12):
                for i in range(32):
                        matrice[j-11][31-((32+i) %32)]=not matrice[j-11][31-((32+i) %32)]

        afficheur.affiche(v,matrice)


    return;
