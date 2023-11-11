#include <iostream>
#include <map>

int main() {
    // Task 1: Initialize data structures
    std::map<std::string, int> journey_up;
    journey_up["09:00"] = 480;
    journey_up["11:00"] = 480;
    journey_up["13:00"] = 480;
    journey_up["15:00"] = 480;

    std::map<std::string, int> journey_down;
    journey_down["10:00"] = 480;
    journey_down["12:00"] = 480;
    journey_down["14:00"] = 480;
    journey_down["16:00"] = 480;
    
    
    int total_passengers_up = 0;
    int total_passengers_down = 0;
    int total_money_up = 0;
    int total_money_down = 0;

    std::cout << "Welcome to Electric Mountain Railway!" << std::endl;

    // Task 2: Purchasing Tickets
    std::string time;
    int num_tickets;
    while (true) {
        std::cout << "Enter the time of the journey (HH:MM) or type 'exit' to end: ";
        std::cin >> time;
        
        if (time == "exit") {
            break;
        }
        
        std::cout << "Enter the number of tickets to purchase: ";
        std::cin >> num_tickets;

        // Validate input and perform ticket purchase logic
        if ((journey_up.find(time) != journey_up.end() && journey_up[time] >= num_tickets) ||
            (journey_down.find(time) != journey_down.end() && journey_down[time] >= num_tickets)) {
            // Tickets available, perform purchase
            int ticket_price = num_tickets * 25;
            if (num_tickets >= 10 && num_tickets <= 80) {
                // Apply group discount
                int free_tickets = num_tickets / 10;
                ticket_price -= free_tickets * 25;
            }
            
            // Update data structures
            if (journey_up.find(time) != journey_up.end()) {
                journey_up[time] -= num_tickets;
                total_passengers_up += num_tickets;
                total_money_up += ticket_price;
            } else if (journey_down.find(time) != journey_down.end()) {
                journey_down[time] -= num_tickets;
                total_passengers_down += num_tickets;
                total_money_down += ticket_price;
            }

            // Display confirmation
            std::cout << "Tickets purchased successfully!" << std::endl;
            std::cout << "Total cost: $" << ticket_price << std::endl;
        } else {
            // Tickets not available for the selected time
            std::cout << "Error: Not enough tickets available for the selected time." << std::endl;
        }
    }

    // Task 3: End of the Day
    std::cout << "\nEnd of the day summary:" << std::endl;
    for (const auto& pair : journey_up) {
        std::cout << "Journey time: " << pair.first << std::endl;
        std::cout << "Total passengers: " << 480 - pair.second << std::endl;
        std::cout << "Total money earned: $" << (480 - pair.second) * 25 << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
    
    // Calculate and display total number of passengers and total money earned
    int total_passengers = total_passengers_up + total_passengers_down;
    int total_money_earned = total_money_up + total_money_down;
    std::cout << "Total passengers for the day: " << total_passengers << std::endl;
    std::cout << "Total money earned for the day: $" << total_money_earned << std::endl;

    // Find the most popular journey
    std::string most_popular_journey;
    int max_passengers = 0;
    for (const auto& pair : journey_up) {
        int passengers = 480 - pair.second;
        if (passengers > max_passengers) {
            max_passengers = passengers;
            most_popular_journey = pair.first;
        }
    }
    std::cout << "Most popular journey of the day: " << most_popular_journey << std::endl;

    return 0;
}
