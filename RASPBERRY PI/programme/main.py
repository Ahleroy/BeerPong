#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Une LED branchee a la pin 25 clignote

import afficheur  # bibliotheque pour utiliser les GPIO
import time              # bibliotheque pour gestion du temps

afficheur.reset()

try:
        import routine
        while True:     # boucle repetee jusqu'a l'interruption du programme
             reload(routine)


except KeyboardInterrupt: afficheur.kill()
