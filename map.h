#include <vector>

#include "tiles.h"

using TMapType = std::vector<std::vector<std::shared_ptr<TTile>>>;

class TGameMap {
public:
    TGameMap(TGameMap const&) = delete;
    void operator=(TGameMap const&) = delete;

    static void Initialize(const uint64_t size) {
        Size = size;
    }

    static TGameMap& GetInstance() {
        static TGameMap inst(Size);
        return inst;
    }

    uint64_t size() const {
        return Map->size();
    }

    std::shared_ptr<TMapType> GetMap() {
        return Map;
    }

    void Build(const uint64_t x, const uint64_t y);

private:
    TGameMap(const uint64_t size) {
        Map = std::make_shared<TMapType>(TMapType(size, std::vector<std::shared_ptr<TTile>>(size, std::make_shared<TTile>(TTile()))));
    }

private:
    static uint64_t Size;
    std::shared_ptr<TMapType> Map;
};
