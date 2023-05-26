# Example code for an Employee Performance Evaluation Expert System

# Define the knowledge base (rules and criteria)
knowledge_base = {
    'attendance': {
        'excellent': {'threshold': 95, 'weight': 0.3},
        'good': {'threshold': 90, 'weight': 0.2},
        'fair': {'threshold': 80, 'weight': 0.1},
        'poor': {'threshold': 0, 'weight': 0},
    },
    'productivity': {
        'excellent': {'threshold': 90, 'weight': 0.3},
        'good': {'threshold': 80, 'weight': 0.2},
        'fair': {'threshold': 70, 'weight': 0.1},
        'poor': {'threshold': 0, 'weight': 0},
    },
    'communication': {
        'excellent': {'threshold': 95, 'weight': 0.3},
        'good': {'threshold': 90, 'weight': 0.2},
        'fair': {'threshold': 80, 'weight': 0.1},
        'poor': {'threshold': 0, 'weight': 0},
    },
    'knowledge': {
        'excellent': {'threshold': 90, 'weight': 0.3},
        'good': {'threshold': 80, 'weight': 0.2},
        'fair': {'threshold': 70, 'weight': 0.1},
        'poor': {'threshold': 0, 'weight': 0},
    },
    'punctuality': {
        'excellent': {'threshold': 95, 'weight': 0.3},
        'good': {'threshold': 90, 'weight': 0.2},
        'fair': {'threshold': 80, 'weight': 0.1},
        'poor': {'threshold': 0, 'weight': 0},
    }
}

# Function to validate percentage input
def validate_percentage_input(input_value):
    try:
        percentage = float(input_value)
        if 0 <= percentage <= 100:
            return percentage
        else:
            raise ValueError
    except ValueError:
        print("Invalid input! Please enter a valid percentage (0-100).")
        return None

# Get user inputs
attendance_percentage = None
productivity_percentage = None
communication_percentage = None
knowledge_percentage = None
punctuality_percentage = None

while attendance_percentage is None:
    attendance_input = input("Enter attendance percentage: ")
    attendance_percentage = validate_percentage_input(attendance_input)

while productivity_percentage is None:
    productivity_input = input("Enter productivity percentage: ")
    productivity_percentage = validate_percentage_input(productivity_input)

while communication_percentage is None:
    communication_input = input("Enter communication percentage: ")
    communication_percentage = validate_percentage_input(communication_input)

while knowledge_percentage is None:
    knowledge_input = input("Enter knowledge percentage: ")
    knowledge_percentage = validate_percentage_input(knowledge_input)

while punctuality_percentage is None:
    punctuality_input = input("Enter punctuality percentage: ")
    punctuality_percentage = validate_percentage_input(punctuality_input)

# Evaluate performance
performance_score = 0.0
for criteria, values in knowledge_base.items():
    for category, details in values.items():
        if criteria == 'attendance':
            if attendance_percentage >= details['threshold']:
                performance_score += details['weight']
        elif criteria == 'productivity':
            if productivity_percentage >= details['threshold']:
                performance_score += details['weight']
        elif criteria == 'communication':
            if communication_percentage >= details['threshold']:
                performance_score += details['weight']
        elif criteria == 'knowledge':
            if knowledge_percentage >= details['threshold']:
                performance_score += details['weight']
        elif criteria == 'punctuality':
            if punctuality_percentage >= details['threshold']:
                performance_score += details['weight']

# Generate performance assessment
if performance_score >= 0.8:
    assessment = "Excellent"
elif performance_score >= 0.6:
    assessment = "Good"
elif performance_score >= 0.4:
    assessment = "Fair"
else:
    assessment = "Poor"

# Provide feedback
feedback = f"Based on the evaluation, your performance is {assessment}."
print(feedback)
