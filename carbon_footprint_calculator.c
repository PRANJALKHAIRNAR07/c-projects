#include <stdio.h>

// Emission factors (approximate values for India)
#define CARBON_PER_KWH 0.9      // kg CO2 per kWh
#define VEHICLE_EMISSION 0.175  // kg CO2 per km

int main(void)
{
    char customer_id[20];
    char customer_name[50];
    long contact_no;

    float current_units, last_units;
    float kilometers, mileage;
    float petrol_used;

    float electricity_emission;
    float vehicle_emission;
    float total_carbon;

    /* ----------- Input Section ----------- */

    printf("Enter Customer ID: ");
    scanf("%s", customer_id);

    printf("Enter Customer Name: ");
    scanf("%s", customer_name);

    printf("Enter Contact Number: ");
    scanf("%ld", &contact_no);

    printf("Enter electricity units consumed this month (kWh): ");
    scanf("%f", &current_units);

    printf("Enter electricity units consumed last month (kWh): ");
    scanf("%f", &last_units);

    printf("Enter total kilometers driven this month: ");
    scanf("%f", &kilometers);

    printf("Enter vehicle mileage (km/l): ");
    scanf("%f", &mileage);

    /* ----------- Calculations ----------- */

    petrol_used = kilometers / mileage;

    electricity_emission = current_units * CARBON_PER_KWH;
    vehicle_emission = kilometers * VEHICLE_EMISSION;

    total_carbon = electricity_emission + vehicle_emission;

    /* ----------- Output Section ----------- */

    printf("\n========== Carbon Footprint Report ==========\n");
    printf("Customer ID      : %s\n", customer_id);
    printf("Customer Name    : %s\n", customer_name);
    printf("Contact Number   : %ld\n", contact_no);

    printf("\nElectricity Emission : %.2f kg CO2\n", electricity_emission);
    printf("Vehicle Emission     : %.2f kg CO2\n", vehicle_emission);
    printf("Petrol Consumed      : %.2f liters\n", petrol_used);

    printf("\nTotal Carbon Footprint: %.2f kg CO2\n", total_carbon);

    /* ----------- Comparison ----------- */

    if (current_units > last_units)
        printf("Electricity usage has increased compared to last month.\n");
    else if (current_units < last_units)
        printf("Electricity usage has decreased compared to last month.\n");
    else
        printf("Electricity usage is the same as last month.\n");

    /* ----------- Suggestions ----------- */

    printf("\nSuggestions:\n");
    printf("- Use energy-efficient appliances\n");
    printf("- Reduce unnecessary vehicle travel\n");
    printf("- Consider renewable energy sources\n");

    printf("\nThank you for checking your carbon footprint!\n");
    printf("=============================================\n");

    return 0;
}
