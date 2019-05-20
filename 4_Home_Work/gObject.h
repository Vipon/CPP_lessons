#ifndef G_OBJECT
#define G_OBJECT

class G_Object
{
public:
    G_Object() = default;
    virtual ~G_Object() = default;
    virtual void draw();
};

#endif //G_OBJECT