# Требования к проекту «Дизеринг изображений» #

# Содержание #

1 [Введение](https://github.com/TischenkoArseny/Dithering/blob/master/Documents/Requirements/Requirements%20Document.md#1-%D0%B2%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5)

2 [Требования пользователя](https://github.com/TischenkoArseny/Dithering/blob/master/Documents/Requirements/Requirements%20Document.md#2-%D1%82%D1%80%D0%B5%D0%B1%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F-%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8F)

2.1 [Программные интерфейсы](https://github.com/TischenkoArseny/Dithering/blob/master/Documents/Requirements/Requirements%20Document.md#21-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%BD%D1%8B%D0%B5-%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D1%84%D0%B5%D0%B9%D1%81%D1%8B)

2.2 [Интерфейс пользователя](https://github.com/TischenkoArseny/Dithering/blob/master/Documents/Requirements/Requirements%20Document.md#22-%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D1%84%D0%B5%D0%B9%D1%81-%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8F)

2.3 [Характеристики пользователей](https://github.com/TischenkoArseny/Dithering/blob/master/Documents/Requirements/Requirements%20Document.md#23-%D1%85%D0%B0%D1%80%D0%B0%D0%BA%D1%82%D0%B5%D1%80%D0%B8%D1%81%D1%82%D0%B8%D0%BA%D0%B8-%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D0%B5%D0%B9)

2.4 [Предположения и зависимости](https://github.com/TischenkoArseny/Dithering/blob/master/Documents/Requirements/Requirements%20Document.md#24-%D0%BF%D1%80%D0%B5%D0%B4%D0%BF%D0%BE%D0%BB%D0%BE%D0%B6%D0%B5%D0%BD%D0%B8%D1%8F-%D0%B8-%D0%B7%D0%B0%D0%B2%D0%B8%D1%81%D0%B8%D0%BC%D0%BE%D1%81%D1%82%D0%B8)

3 [Системные требования](https://github.com/TischenkoArseny/Dithering/blob/master/Documents/Requirements/Requirements%20Document.md#3-%D1%81%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D0%BD%D1%8B%D0%B5-%D1%82%D1%80%D0%B5%D0%B1%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F)

3.1 [Функциональные требования](https://github.com/TischenkoArseny/Dithering/blob/master/Documents/Requirements/Requirements%20Document.md#31-%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%BE%D0%BD%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5-%D1%82%D1%80%D0%B5%D0%B1%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F)

3.2 [Нефункциональные требования](https://github.com/TischenkoArseny/Dithering/blob/master/Documents/Requirements/Requirements%20Document.md#32-%D0%BD%D0%B5%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%BE%D0%BD%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5-%D1%82%D1%80%D0%B5%D0%B1%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F)

# 1 Введение #

Приложение «Дизеринг изображений» является настольным приложением, предназначенным для уменьшения размера изображения с наименьшим уменьшением качества. Перспектива развития – интеграция в мессенджеры.

# 2 Требования пользователя #

## 2.1 Программные интерфейсы ##

Приложение будет обрабатывать загружаемы параметры в соответствии с выбранным методом.

## 2.2 Интерфейс пользователя ##

Окно загрузки изображения и выбора количества цветов в итоговом варианте.

 ![Рисунок 1](https://github.com/TischenkoArseny/Dithering/blob/master/Images/MainWindow.png)

Окно выбора метода дизеринга и его применение.

 ![Рисунок 2](https://github.com/TischenkoArseny/Dithering/blob/master/Images/SettingsWindow.png)
 
## 2.3 Характеристики пользователей ##

Приложение ориентировано в первую очередь на людей, находящихся в местности с низкоскоростным доступ в сеть интернет.

## 2.4 Предположения и зависимости ##

Возможно замедление работы приложения при работе с изображениями в высоком разрешении.

# 3 Системные требования #

## 3.1	 Функциональные требования ##

3.1.1 Возможность ручного выбора количества цветов в итоговом варианте палитры. Палитра – совокупность всех цветов в изображении.

3.1.2 Возможность выбора из списка методов дизеринга подходящего для ситуации.

3.1.3 Возможность сохранения итогового изображения, итоговое изображение – изображение после работы одного из методов дизеринга.

3.1.4 Возможность открытия изображений различного размера.

## 3.2 Нефункциональные требования ##

### 3.2.1 Атрибуты качества ###

3.2.1.1 Требования к удобству пользования

Быстрый доступ к основному функционалу приложения, а именно 5-6 нажатия в зависимости от стартового метода дизеринга.

3.2.2.2 Ограничения 

Приложение устанавливается на ПК с ОС Windows 8.1 и выше.
