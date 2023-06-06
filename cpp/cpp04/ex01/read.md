Deep vs shallow copy

    class Test {
        int *p;

        Test (int x)
        {
            this->x = new int (x);
        }
        Test (Test &obj)
        {
            this->x = obj.x;
        }
    }
    
Hier zal met Test T (5) een object worden aangemaakt. Als je dan Test T1 (T) 
zou uitvoeren heeft T1 dezelfde waarvoor p als T. Oftewel in deze copy constructor
wordt een shallow copy aangemaakt. 