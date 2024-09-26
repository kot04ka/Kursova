# Kursovac_c++
 
ВСТУП

У сучасному технологічному світі велику частину інформації займає графічна інформація. За останні роки середня кількість візуальних об’єктів в наукових ма-теріалах виросла майже втричі , що призвело до великої ресурсозатратності з боку технічної частини нашого життя. На жаль , не всі люди можуть забезпечити себе подібними апаратними та програмними засобами для дослідження і обробки су-часної  візуальної  інформації. Тому дуже важливо забезпечити гарну оптимізацію при обробці множин графічних об’єктів.
При обробці візуальної інформації найбільше страждає оперативна пам’ять. І тому для забезпечення ефективності під час подібного виду робіт треба звернути свою увагу на зменшення навантаження на ОП. для зменшення навантаження на RAM можна використовувати різні методи та iнструменти.
Основними методами для забезпечення оптимізації можна вважати:
	метод лінивої ініціалізації - це метод програмування, який відкладає ство-рення та ініціалізацію об'єкта або значення до моменту, коли вони дійсно стануть необхідними. В контексті об'єктно-орієнтованого програмування це означає, що об'єкт не буде створений або ініціалізований, поки не буде викликаний його метод або не буде здійснений доступ до його атрибуту;
	метод стиснення даних - це техніка, що використовується для зменшення розміру даних без втрати їх суттєвої інформації. Це досягається шляхом видален-ня надлишковості, яка присутня у вихідних даних;
	метод використання спеціалізованих структур даних - це спосіб організації даних у комп'ютерах, де використовуються конкретні типи структур даних, опти-мізовані під певні завдання або алгоритми. Ці спеціалізовані структури дозволяють досягти більшої ефективності, простоти, надійності або безпеки обробки даних, порівняно з загальними структурами даних, такими як масиви, списки, словники та інші методи.
Метою курсової роботи є розробка програми з використанням класів - TreeType классу, похідного від нього TreeFactory , застосовуючі концепції ООП, а саме - успадкування класів та поліморфізма. Також для реалізації завдання були використані динамічні масиви даних стандартної бібліотеки шаблонів STL- кон-тейнер map та патерн Легковаговик
 
1 ПОСТАНОВКА ЗАДАЧІ

Розробити контейнерний клас для збереження та обробки масиву фабрики фра-гментів вузлів дерева за паттерном «Легковаговик». Для цього розробити класи: 
	графічного об’єкту – TreeType, який описує не унікальні поля об’єкта дере-ва;
	фабрика легковаговиків – TreeFactory, яка визначає метод створення/ вико-ристання графічного об’єкту(TreeType,);
	збереження контекстного об’єкту Tree .
Програма курсової роботи повинна зберігати та зчитувати дані контейнеру у зовнішньому файлі, мати меню для обробки контейнеру (відкриття файлу з кон-тейнером, збереження, редагування, додання, видалення записів, сортування, по-шук, друк та інше).
 
2 ОСНОВНА ЧАСТИНА

2.1 Аналіз вхідних та вихідних даних

Тестова програма розробленої ієрархії класів буде зберігати масив  даних ко-жного графічного об’єкту , а саме: Ідентифікатор типу, колір, текстура, висота ,ширина , код об’єкта.
Вхідними даними розробленої тестової програми є значення елементів ієрар-хії класів - код об’єкта, номер пункту меню для виконання дії над елементами кон-тейнеру - deque, введених з клавіатури або отримані з зовнішнього файлу
Вихідні дані програми є: вивід даних ієрархії класів на екран або редагуван-ня/запис файлу за вимогами користувача.


2.2 Методи та засоби програмування

Для виконання поставленого завдання курсової роботи необхідні такі розділи програмування мовою С++, як:
	класи;
	абстрактні типи даних та інкапсуляція  класу;
	агрегацiя;
	контейнер STL – map;
	інструменти роботи з файловими потоками вводу – виводу.
Інкапсуляція – це концепція об’єктно-орієнтованого програмування, що озна-чає поєднання властивостей (атрибутів або даних) та методів в одне ціле. Деякі ав-тори ототожнюють інкапсуляцію з приховуванням (англ. information hiding) , у той час як інші ні (відокремлюють ці визначення) . 
