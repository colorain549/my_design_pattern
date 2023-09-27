# 单例模式(Point)

## 0_point.cc
```
// 略
```

## 1_point.cc
```
public:
    step 2: &getInstance
    static Point &getInstance()
    {
        // 思考: 实例化对象为什么需要static
        // 思考: 全局访问???
        static Point pt(2, 3);
        return pt;
    }
```

## 2_point.cc
```
public:
    // step 3 *getInstance
    static Point *getInstance()
    {
        if (_pInstance == nullptr)
        {
            // step 6 若不希望传实参,显化默认构造函数
            // _pInstance = new Point(3, 4);
            _pInstance = new Point();
        }
        return _pInstance;
    }
```

## 3_point.cc
```
public:
    // step 7 显化默认构造函数
    Point() = default;

    // step 8 init
    void init(int ix, int iy)
    {
        _ix = ix;
        _iy = iy;
    }

    // step 9 delete
    void destroy()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
```