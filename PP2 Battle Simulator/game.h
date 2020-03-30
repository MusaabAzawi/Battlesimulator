#pragma once

namespace Tmpl8
{
//forward declarations
class Tank;
class Rocket;
class Smoke;
class Particle_beam;

class Game
{
  public:
    void SetTarget(Surface* surface) { screen = surface; }
    void Init(); 
    void Grid();
    void Shutdown();
    void Update(float deltaTime);
    void Draw();
    vector<Tank*> mergeSort_tanks_health(std::vector<Tank*> original);
    vector<Tank*> mergeSort(std::vector<Tank*> l, std::vector<Tank*> r);
    void Tick(float deltaTime);
    void insertion_sort_tanks_health(const std::vector<Tank>& original, std::vector<const Tank*>& sorted_tanks, UINT16 begin, UINT16 end);
    //void quicksort_tanks_health(vector<const Tank*>& sorted_tanks, int left, int right);
    void sortTanks(std::vector<Tank>& original, std::vector<Tank*>& sorted_tanks);
    void MeasurePerformance();
    void updateTanks();
    void updateSmoke();
    void updateBiem();
    void updateExpl();
  //  void ShootRocket(Tank& tank);
    void updateRocket(vector<Rocket*>& rockets, int from, int to);
    

    Tank& FindClosestEnemy(Tank& current_tank);
    void updateGrid(Tank& current_tank);
    void erase_from_vector(vector<Tank*>& pVector, const Tank& tank);
    vector<Rocket*> rocketpointer;
    ThreadPool pool{4};

    void MouseUp(int button)
    { /* implement if you want to detect mouse button presses */
    }

    void MouseDown(int button)
    { /* implement if you want to detect mouse button presses */
    }

    void MouseMove(int x, int y)
    { /* implement if you want to detect mouse movement */
    }

    void KeyUp(int key)
    { /* implement if you want to handle keys */
    }

    void KeyDown(int key)
    { /* implement if you want to handle keys */
    }

  private:
    Surface* screen;
    
    vector<Tank> tanks;
    vector<Rocket> rockets;
    vector<Smoke> smokes;
    vector<Explosion> explosions;
    vector<Particle_beam> particle_beams;
    vector<vector<vector<Tank*>>> grid;
    vector<Tank*> outOfGrid;

    Font* frame_count_font;
    long long frame_count = 0;

    bool lock_update = false;
};

}; // namespace Tmpl8