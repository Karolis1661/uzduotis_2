Paruošti dynamic library (.so), kuriame būtų įgyvendintas Linked List principu veikiantis sąrašas.
Apgalvoti galimus variantus dėl ne konkretaus tipo elemento pridėjimo (void *) ir apie galimybę
paruošti šią biblioteką Thread Safe. Reikėtų padaryti iškeliamą header (*.h) failą, kuriame būtų
deklaruotos funkcijos, tik kurias gali pasiekti vartotojas (funkcijų deklaracijos privalo būti
dokumentuotos DoxyGen principu). Ši biblioteka turi turėti savo struktūrą, kuri būtu tik deklaruota
išorei, be papildomų parametrų (typedef struct linked_list;), kad darbas būtų atliekamas tik su
deklaruotomis funkcijomis iš šios bibliotekos, paduodant sąrašo kintamajį (pop(manoKintamasis);).
PS. sąrašo viduje atmintis privalo būti tvarkoma dinamiškai, be jokių memory leak.

***** Valgrind testas

Main():

![prog](https://user-images.githubusercontent.com/67113855/113329536-6061e200-9326-11eb-991e-7c3d8097edf8.jpg)

1-as bandymas:

![valgrind](https://user-images.githubusercontent.com/67113855/113329584-6bb50d80-9326-11eb-9c73-7f97944b90ba.jpg)

Lieka atlaisvinti pati p_head

![image](https://user-images.githubusercontent.com/67113855/113329851-c2bae280-9326-11eb-8c5e-70a5042075db.png)

![image](https://user-images.githubusercontent.com/67113855/113329889-cfd7d180-9326-11eb-9435-c369bec44023.png)
