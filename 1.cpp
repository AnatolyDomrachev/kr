







// подключение заголовочных файлов. Нужны для использования некоторых функций 
#include <iostream> //для cin, cout
#include <vector> // для типа даннеых vector
#include <cstring> // для strcmp



using namespace std; // Установка пространства имён. Чтобы использовать cin, cout
//описание структур
struct product // структура для хранения продуктов
{
    int id;
    char name[50];
    char category[50];
    char producer[50];
};

struct store
{
    int id;//int - тип данных (целое число) id - имя переменной;
    char name[50];// массив типа char размером 50
    char address[100];
    char phone[20];
};

// глобальные переменные
vector<struct product> prods; //объявление вектора prods. вектор - как массив, но удобнее работать. Он знает свой размер, может динамически расширяться, удобнее организовывать циклы. Тип данных вектора struct products
vector<struct store> stors;
vector<int> result;//вектор целых чисел для хранения результатов поиска
int max_id_products = 0;//Идентификатор продуктов. У каждой записи будет свой уникальный идентификатор на 1 больше, чем у предыдущей
int max_id_stores= 0;
// Объявление функций.
void add_product();
void add_store();
void show_products();
void show_stores();
void search_stores_by_name();
void search_products_by_name();
void search_products_by_category();
void sort_stores_by_name();
void sort_products_by_name();
void sort_products_by_category();
void save_to_file_stores();
void save_to_file_products();
void load_from_file_stores();
void load_from_file_products();
void remove_stores();
void remove_products();

int main()//с функции main всегда начинается запуск программы
{
    int n;//число, которое будет введено пользователем в главном меню
    while(true)//начало бесконечного цикла, главное меню будет выводиться, пока не будет выбрано завершение программы
    {
	cout << "Enter:" << endl;// вывод строки на экран
	cout << "1 - add product" << endl;
	cout << "2 - add store" << endl;
	cout << "3 - show products" << endl;
	cout << "4 - show stores" << endl;
	cout << "5 - search stores by name" << endl;
	cout << "6 - search products by name" << endl;
	cout << "7 - search products by category" << endl;
	cout << "8 - sort stores by name" << endl;
	cout << "9 - sort products by name" << endl;
	cout << "10 - sort products by category" << endl;
	cout << "11 - save to file stores" << endl;
	cout << "12 - save to file products" << endl;
	cout << "13 - load from file stores" << endl;
	cout << "14 - load from file products" << endl;
	cout << "15 - exit" << endl;

	cin >> n; // ввод числа пользователем
	switch (n) // Выполнение кода в зависимости от значения n, которое ввёл пользователь
	{	
	    case 1:
		add_product();//если n=1 вызвать эту функцию
		break; // и больше ничего не делать
	    case 2:
		add_store();
		break;
	    case 3:
		show_products();
		break;
	    case 4:
		show_stores();
		break;
	    case 5:
		search_stores_by_name();
		break;
	    case 6:
		search_products_by_name();
		break;
	    case 7:
		search_products_by_category();
		break;
	    case 8:
		sort_stores_by_name();
		break;
	    case 9:
		sort_products_by_name();
		break;
	    case 10:
		sort_products_by_category();
		break;
	    case 11:
		save_to_file_stores();
		break;
	    case 12:
		save_to_file_products();
		break;
	    case 13:
		load_from_file_stores();
		break;
	    case 14:
		load_from_file_products();
		break;
	    case 15:
		return 0; // закончить программу с кодом 0 (соответствует праильному завершению программы)
		break;
	    default:// если пользователь ввёл нечто, чего нет в меню
		return 1; // закончить с кодом 1 - завершение с ошибкой
	}
    }
    return 0; // завершить программу (завершение функции main это завершение программы)
}

void add_product()// реализация функции
{
    struct product n; //переменная n типа struct product. Нужна для того, чтобы заполнить её, а затем поместить в вектор prods (описан выше) 
    n.id = max_id_products; //поле id структуры n равно max_id_products(описан в глобальных переменных)
    max_id_products++;//увеличение max_id_products на 1
    cout << "Add new product.\n";// \n - перевод строки
    cout << "Enter name: ";
    cin >> n.name;//ввод поля name
    cout << "Enter category: ";
    cin >> n.category;
    cout << "Enter producer: ";
    cin >> n.producer;
    prods.push_back(n);// Добавление заполненного n в вектор
}

void add_store()
{
    struct store n;
    n.id = max_id_stores;
    max_id_stores++;
    cout << "Add new store.\n";
    cout << "Enter name: ";
    cin >> n.name;
    cout << "Enter address: ";
    cin >> n.address;
    cout << "Enter phone: ";
    cin >> n.phone;
    stors.push_back(n);
}

void show_products()
{
    cout << "id\t|\t" << "name\t|\t" << "category\t|\t" << "producer" << endl ;// \t - отступ
    for (auto &n : prods) // цикл прохода по вектору. n принимает по очереди все значения из вектора prods и с такими значениями выполняется следующая строка
	cout << n.id << "\t|\t" << n.name << "\t|\t" << n.category<< "\t|\t"  << n.producer << endl ;
}

void show_stores()
{
    cout << "id\t|\t" << "name\t|\t" << "address\t|\t" << "phone" << endl ;
    for (auto &n : stors) 
	cout << n.id << "\t|\t" << n.name << "\t|\t" << n.address<< "\t|\t" << n.phone<< endl ;
}

void search_stores_by_name()
{
    int n;
    char name[50];
    int count = 0;//количество найденных продуктов, нужно по заданию
    result.clear();
    cout << "Enter name for search: ";
    cin >> name;
    cout << "id\t|\t" << "name\t|\t" << "address\t|\t" << "phone" << endl ;

    for (auto &n : stors)
	if(!strcmp(n.name, name))// проверка того, что то, что ввёл пользователь равно тому, что записано в векторе. strcmp - сравнение двух строк. В случае если они равны возвращает 0, поэтому нужен !, чтобы превратить 0 в не 0, так как при "не ноле" выполняется то, что в фигурных скобках ниже (оператор if)
	{
	    cout << n.id << "\t|\t" << n.name << "\t|\t" << n.address<< "\t|\t" << n.phone<< endl ;// вывод на экран
	    result.push_back(n.id);//добавление идентификатора магазина в вектор result
	    count++;//увеличение на 1
	}
    cout << "Count of result = " << count << endl << endl;
    cout << "Enter:\n";
    cout << "1 - Remove these notes" << endl;
    cout << "2 - Back to main menu" << endl;
    cin >> n ;
    switch(n)
    {
	case 1:
	    remove_stores();
	    break;
	case 2:
	    break;
    }
}

void search_products_by_name()
{
    int n;
    char name[50];
    int count = 0;
    result.clear();
    cout << "Enter name for search: ";
    cin >> name;
    cout << "id\t|\t" << "name\t|\t" << "category\t|\t" << "producer" << endl ;

    for (auto &n : prods)
	if(!strcmp(n.name, name))
	{
	    cout << n.id << "\t|\t" << n.name << "\t|\t" << n.category<< "\t|\t"  << n.producer << endl ;
	    result.push_back(n.id);
	    count++;
	}
    cout  << "Count of result = " << count << endl << endl ;
    cout << "Enter:\n";
    cout << "1 - Remove these notes" << endl;
    cout << "2 - Back to main menu" << endl;

    cin >> n ;
    switch(n)
    {
	case 1:
	    remove_products();
	    break;
	case 2:
	    break;
    }
}

void search_products_by_category()
{
    int n;
    char category[50];
    int count = 0;
    result.clear();
    cout << "Enter name for search: ";
    cin >> category;
    cout << "id\t|\t" << "name\t|\t" << "category\t|\t" << "producer" << endl ;

    for (auto &n : prods)
	if(!strcmp(n.category, category))
	{
	    cout << n.id << "\t|\t" << n.name << "\t|\t" << n.category<< "\t|\t"  << n.producer << endl ;
	    result.push_back(n.id);
	    count++;
	}
    cout  << "Count of result = " << count << endl << endl ;
    cout << "Enter:\n";
    cout << "1 - Remove these notes" << endl;
    cout << "2 - Back to main menu" << endl;
    cin >> n ;
    switch(n)
    {
	case 1:
	    remove_products();
	    break;
	case 2:
	    break;
    }
}

void remove_stores()
{
    int i;
    for (auto &id : result)//цикл по вектору result
	for (i=0; i<stors.size();i++)//цикл по вектору stors
	    if(stors[i].id == id)//если идентификатор магазина совпал с идентифиактором из вектора result (заполненный в функции search) то выполнить то, что в фигурных скобках
	    {
		stors.erase(stors.begin()+i);//удалить магазин из вектора
		break;// выйти из этого цикла, так как искомый магазин уже найден, и дальша искать не нужно
	    }
}

void remove_products()
{
    int i;
    for (auto &id : result)
	for (i=0; i<prods.size();i++)
	    if(prods[i].id == id)
	    {
		prods.erase(prods.begin()+i);
		break;
	    }
}

void sort_stores_by_name() // сортировка методом Пузырька
{
    int i,j,min_j;// переменные, нужные для сортировки.
    struct store min, tmp;// структуры, нужные для сортировки
    for (i=0; i<stors.size();i++)
    {
	min_j = i;
	min = stors[i];

	for (j=i+1;j<stors.size();j++)
	    if(strcmp(stors[j].name, min.name) < 0)// сравнение двух строк, какая идёт раньше по алфавиту
	    {
		min = stors[j];
		min_j = j;
	    }//конец второго цикла for

	iter_swap(stors.begin()+i, stors.begin()+min_j);//поменять местами два элемента вектора stors
    }//конец первого цкла for
    show_stores();// вызов функции
}

void sort_products_by_name()
{
    int i,j,min_j;
    struct product min, tmp;
    for (i=0; i<prods.size();i++)
    {
	min_j = i;
	min = prods[i];

	for (j=i+1;j<prods.size();j++)
	    if(strcmp(prods[j].name, min.name) < 0)
	    {
		min = prods[j];
		min_j = j;
	    }

	iter_swap(prods.begin()+i, prods.begin()+min_j);
    }
    show_products();
}

void sort_products_by_category()
{
    int i,j,min_j;
    struct product min, tmp;
    for (i=0; i<prods.size();i++)
    {
	min_j = i;
	min = prods[i];

	for (j=i+1;j<prods.size();j++)
	    if(strcmp(prods[j].category, min.category) < 0)
	    {
		min = prods[j];
		min_j = j;
	    }

	iter_swap(prods.begin()+i, prods.begin()+min_j);
    }
    show_products();
}

void save_to_file_stores()
{
    char fname[50];
    cout << "Enter file name: ";
    cin >> fname;//ввод имени файла для записи
    FILE * hfile = fopen(fname , "w");//открытие файла для записи
    fwrite(&stors[0], sizeof(struct store),stors.size(),hfile );//запись в файл всего вектора stors. sizeof(struct store) - размер структуры в байтах,stors.size() - количество элементов 
    fclose(hfile);//закрытие  файла
}

void save_to_file_products()
{
    char fname[50];
    cout << "Enter file name: ";
    cin >> fname;
    FILE * hfile = fopen(fname , "w");
    fwrite(&prods[0], sizeof(struct product),prods.size(),hfile );
    fclose(hfile);
}

void load_from_file_stores()
{   
    stors.clear();//очистка вектора stors
    char fname[50];
    struct store buf;//структура для в неё данных из файла
    cout << "Enter file name: ";
    cin >> fname;
    FILE * hfile = fopen(fname , "r");//открытие файла для чтения
    while(fread(&buf, sizeof(struct store),1,hfile))//цикл "до тех пор, пока удаётся прочитать из файла количество байт, равное размеру структуры в структуру buf"
	stors.push_back(buf); // добавление buf в вектор stors
    fclose(hfile);
}

void load_from_file_products()
{
    prods.clear();
    char fname[50];
    struct product buf;
    cout << "Enter file name: ";
    cin >> fname;
    FILE * hfile = fopen(fname , "r");
    while(fread(&buf, sizeof(struct product),1,hfile))
	prods.push_back(buf);
    fclose(hfile);
}

