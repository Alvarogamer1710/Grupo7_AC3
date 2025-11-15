#include <iostream>


template <typename t>
class Dynarry
{
private:
    t *data;
    size_t size;
    size_t capacity;

public:
    Dynarry()
    {
        size = 0;
        capacity = 0;
        data = nullptr;
    };

    ~Dynarry()
    {
        delete[] data;
    };

    void insert(t e)
    {
        if (size == capacity)
        {
            if (capacity == 0)
            {
                t *aux = new t[2];
                data = aux;
                capacity = 2;
            }
            else
            {
                size_t newCap = capacity * 2;
                t *aux = new t[newCap];
                for (size_t i = 0; i < size; i++)
                {
                    aux[i] = data[i];
                }
                delete[] data;
                data = aux;
                capacity = newCap;
            }
        }
        data[size] = e;
        size++;
    }

    void remove(t e)
    {
        if (size == 0)
        {
            std::cout << "El Dynarray está vacío, no se puede eliminar ningún elemento." << std::endl;
        }
        else
        {
            size_t index = size;
            for (size_t i = 0; i < size; i++)
            {
                if (data[i] == e)
                {
                    index = i;
                    break;
                }
            }
            if (index == size)
            {
                std::cout << "El elemento no se encontró en el Dynarray." << std::endl;
            }
            else
            {
                for (size_t i = index; i < size - 1; i++)
                {
                    data[i] = data[i + 1];
                }
                size--;
            }
        }
    }

    void buscar(t e)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (data[i] == e)
            {
                std::cout << "Elemento " << e << " encontrado en el índice " << i << "." << std::endl;
                return;
            }
        }
        std::cout << "Elemento " << e << " no encontrado en el Dynarray." << std::endl;
    }

public:
    // Retorna el tamaño actual del array
    int getDynarraySize()
    {
        return this->size;
    }

    // Sobrecarga del operador [] que sirve para acceder a los elementos del Dynarray
    t &operator[](int index)
    {
        if (index >= 0 && index < this->size)
        {
            return data[index];
        }
    }

    // Sobrecarga del operador [], para acceder a los elementos del Dynarray en modo constante (que no se pueden modificar)
    const t &operator[](int index) const
    {
        if (index >= 0 && index < this->size)
        {
            return data[index];
        }
    }
};




// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}