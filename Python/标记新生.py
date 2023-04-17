import xlrd
import pymysql

book = xlrd.open_workbook('C:/Users/伍学明/Desktop/职高.xls')

sheet1 = book.sheets()[0]

nrows = sheet1.nrows

print('表格总行数', nrows)

ncols = sheet1.ncols

print('表格总列数', ncols)

col1_values = list(map(int, sheet1.col_values(0)))

# 1. 连接数据库，
conn = pymysql.connect(
    host='120.78.162.102',
    user='root',
    password='jsuccw2110',
    db='jol',
    charset='utf8',
       # autocommit=True,    # 如果插入数据，， 是否自动提交? 和conn.commit()功能一致。
)
# ****python, 必须有一个游标对象， 用来给数据库发送sql语句， 并执行的.
# 2. 创建游标对象，
cur = conn.cursor()

# 3). *********************插入多条数据****************************
try:
    info = [(user_id) for user_id in col1_values]
    # *********************第二种方式********************
    insert_sqli = "insert into zhigao (user_id) values ('%s');"
    cur.executemany(insert_sqli, info)
except Exception as e:
    print("更新多条数据失败:", e)
else:
    # 如果是插入数据， 一定要提交数据， 不然数据库中找不到要插入的数据;
    conn.commit()
    print("更新多条数据成功;")
# 4. 关闭游标
cur.close()
# 5. 关闭连接
conn.close()
