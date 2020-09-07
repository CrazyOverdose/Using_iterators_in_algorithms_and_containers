# Удаление повторов

Напишите шаблонную функцию RemoveDuplicates, принимающую по ссылке вектор elements объектов типа T и удаляющую из него все дубликаты элементов. Порядок оставшихся элементов может быть любым.

Гарантируется, что объекты типа T можно сравнивать с помощью операторов ==, !=, < и >.

```
template <typename T>
void RemoveDuplicates(vector<T>& elements);
```

# Перебор перестановок

Дано целое положительное число N, не превышающее 9. Выведите все перестановки чисел от 1 до N в обратном лексикографическом порядке.

# Демографические показатели

В этой задаче вам необходимо вычислить различные демографические показатели для группы людей. Человек представляется структурой Person:

```
struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};
```

Тип Gender определён следующим образом:

```
enum class Gender {
  FEMALE,
  MALE
};
```

Вам необходимо написать функцию PrintStats, получающую вектор людей, вычисляющую и выводящую медианный возраст для каждой из следующих групп людей:

+ все люди;
+ все женщины;
+ все мужчины;
+ все занятые женщины;
+ все безработные женщины;
+ все занятые мужчины;
+ все безработные мужчины.

Все 7 чисел нужно вывести в строгом соответствии с форматом.

```
void PrintStats(vector<Person> persons);
```

