# AutoTopic_Demo
自动出题程序/Automatic test program  
  
    该程序主要用于在熟悉考研教材大纲的基础上，方便对考试题目以名词解释、简答题、论述题为主的试题知识点的掌握程度进行检测。  
运行效果展示：  
![image](https://github.com/ChengLion/AutoTopic_Demo/blob/main/pic/AutoTopic_AaKfnSDQ2Z.png)
  
试题文件保存在根目录“TEST”文件夹中，题目内容格式如下：  
![image](https://github.com/ChengLion/AutoTopic_Demo/blob/main/pic/notepad_i1oRkUbDFZ.png)
  
M,这是M类型的题目,答案页码,属性;  
J,这是J类型的题目,答案页码,属性;  
L,这是L类型的题目,答案页码,属性;  
M代表名词解释、J代表简答题、L代表论述题。  
  
程序通过打乱vetor容器内容顺序来保证出题的随机性。  
试题txt文件标点均为英文字符，字符编码需设置为ANSI。
