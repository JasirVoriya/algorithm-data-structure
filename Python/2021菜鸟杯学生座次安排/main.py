import xlrd
import xlwt

book = xlrd.open_workbook('2021级软件工程花名册.xls')
res_book = xlwt.Workbook(encoding='utf-8', style_compression=0)
res_sheet = res_book.add_sheet('菜鸟杯座次安排表', cell_overwrite_ok=True)


classes = list()
for sheet in book.sheets():
    class_temp = list()
    for i in range(sheet.nrows):
        row = sheet.row_values(i)
        row.append(sheet.name)
        row.pop(0)
        row[1] = int(row[1])
        class_temp.append(list(map(str, row)))
        # class_temp.append(row)
        pass
    classes.append(class_temp)
    pass
class_cnt = [len(x) for x in classes]
res = list()
cnt = 0
for i in range(max(class_cnt)):
    for j in range(len(classes)):
        try:
            for index, x in enumerate(classes[j][i]):
                res_sheet.write(cnt, index, x)
            print(classes[j][i])
            cnt += 1
        except:
            pass
        pass
    pass
res_book.save('菜鸟杯座次安排表.xls')

print('总排列人数：', cnt)
print('总新生人数：', sum(class_cnt))
