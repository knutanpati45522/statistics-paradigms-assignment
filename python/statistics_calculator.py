class StatisticsCalculator:
    def __init__(self, values):
        if not values:
            raise ValueError("The values list cannot be empty.")
        self.values = list(values)

    def mean(self):
        return sum(self.values) / len(self.values)

    def median(self):
        sorted_values = sorted(self.values)
        n = len(sorted_values)
        mid = n // 2
        if n % 2 == 1:
            return float(sorted_values[mid])
        return (sorted_values[mid - 1] + sorted_values[mid]) / 2

    def mode(self):
        freq = {}
        for value in self.values:
            freq[value] = freq.get(value, 0) + 1

        max_count = max(freq.values())
        if max_count == 1:
            return [], max_count

        modes = [value for value, count in sorted(freq.items()) if count == max_count]
        return modes, max_count


if __name__ == "__main__":
    values = [4, 1, 2, 2, 3, 4, 5, 4, 2, 6, 7, 2, 4]
    calc = StatisticsCalculator(values)

    print("Python (Object-Oriented) Statistics Calculator")
    print(f"Input values: {values}")
    print(f"Mean: {calc.mean():.2f}")
    print(f"Median: {calc.median():.2f}")

    modes, frequency = calc.mode()
    if not modes:
        print("Mode: No mode (all values occur once)")
    else:
        mode_text = ", ".join(str(m) for m in modes)
        print(f"Mode(s): {mode_text} (frequency = {frequency})")
