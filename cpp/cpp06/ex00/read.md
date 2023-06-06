CPP Casts



ex00 gebruikt alleen static_cast want: 
tijdens compile
static cast is meest simpele, maakt gewoon van float een int etc. 
Gebeurt tijdens compilen. 



ex01 gebruikt allen reinterpret_cast

maakt van een pointer type een andere pointer type ,checkt niet of dat 'kan'

reinterpret_cast only guarantees that if you cast a pointer to a different type, and then reinterpret_cast it back to the original type, you get the original value. So in the following:

int* a = new int();
void* b = reinterpret_cast<void*>(a);
int* c = reinterpret_cast<int*>(b);

dus in geval van ons willen we casten van Data* -> uintptr_t en andersom.
En dan dezelfde waardes houden (dus gebuirk je reinterpret cast)
De memoryadres print kan op andere machines andere waardes geven!




ex02 gebruikt dynamic_cast.
Dit zodat tijdens runtime gekeken wordt naar welke conversies kunnen.

In geval van identify (Base *) returned de dynamic cast als het niet kan 
een nullptr.

In geval van identify (Base &) throwt dynamic cast een exception





