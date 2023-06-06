HumanA gebruikt een reference naar Weapon omdat bij het aanmaken van de class
er altijd een weapon met worden meegegeven (een reference kan niet 'leeg' zijn)

Bij HumanB gebruik je een pointer omdat deze wel een 'leeg' weapon moet kunnen hebben.

Reference moet dus altijd naar iets refereren en bij pointer hoeft dat niet.

Pointer heeft een address van een variable: 

int *p;
int a = 3;
p = &a;

Reference is een alias (dus hij heeft geen addres oid). Na initialisatie (die altijd gelijk moet gebeuren)
kan je de reference niet meer wijzigen. 

int a = 3;
int &ref = a;

Een reference kan je oproepen door enkel de naam te gebruiken (ipv van dereferencen bij pointers).
