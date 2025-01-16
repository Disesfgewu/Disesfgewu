import subprocess
import json
import os

os.environ['PYTHONIOENCODING'] = 'utf-8'

# Function to query Llama model
def query_llama(prompt):
    try:
        result = subprocess.run(
            ['ollama', 'run', 'llama3.2'],  
            input=prompt,                   
            stdout=subprocess.PIPE,         
            stderr=subprocess.PIPE,         
            text=True,                      
            encoding="utf-8"                
        )
        # print(f"DEBUG: Raw stdout: {result.stdout.strip()}")
        # print(f"DEBUG: stderr: {result.stderr.strip()}")

        if result.returncode != 0:
            print(f"Error from Ollama: {result.stderr.strip()}")
            return None

        return result.stdout.strip()
    except UnicodeDecodeError as e:
        print(f"UnicodeDecodeError: {e}")
        return None
    except Exception as e:
        print(f"Error interacting with Ollama: {e}")
        return None

def extract_key_sentences(response, max_sentences=2):
    """Extract the first few sentences as key points."""
    sentences = response.split(". ")  
    return ". ".join(sentences[:max_sentences]) 

def load_patient_data(file_path="patient_data.json"):
    try:
        with open(file_path, "r", encoding="utf-8") as f:
            return json.load(f)
    except FileNotFoundError:
        print("Patient data file not found. Make sure `patient_data.json` exists.")
        return {}

def chatbot():
    print("Chatbot: Hello! Type 'query patient <ID>' to load patient data, or type 'exit' to quit.")

    patient_data = load_patient_data()
    active_patient = None

    while True:
        user_input = input("You: ")

        if user_input.lower() == "exit":
            print("Chatbot: Goodbye!")
            break
        elif user_input.startswith("query patient"):
            global patient_id 
            patient_id = user_input.replace("query patient", "").strip()
            if patient_id in patient_data:
                active_patient = patient_data[patient_id]
                print(f"Chatbot: Patient data loaded: {active_patient}")
                file = open( f"./history/{patient_id}.txt" , "+w" , encoding="utf-8" )
                file.write(f"Patient data loaded: {active_patient}\n" )
                file.close()
            else:
                print(f"Chatbot: No data found for patient ID '{patient_id}'.")

        elif user_input.startswith("ask"):
            if not active_patient:
                print("Chatbot: No patient data loaded. Use 'query patient <ID>' first.")
                continue

            question = user_input.replace("ask", "").strip()
            prompt = f"""
            Patient Data:
            - SpO2: {active_patient['SpO2']}%
            - Heart Rate: {active_patient['heart_rate']} bpm
            - Temperature: {active_patient['temperature']}°C
            - Symptoms: {active_patient['symptoms']}

            Question: {question}

            Please provide an analysis and recommendations based on the above data.
            Please provide the answer in the maximum 2 sentences , it's important!
            """
            response = query_llama(prompt)
            if response:
                key_sentences = extract_key_sentences(response)
                print(f"Chatbot: {key_sentences}")
                file = open( f"./history/{patient_id}.txt" , "a+" , encoding="utf-8" )
                file.write( "question: " + question + '\n' )
                file.write( "chatbot: " + key_sentences + '\n' )
                file.close()
            else:
                print("Chatbot: Could not retrieve a response. Please try again later.")

        else:
            print("Chatbot: Sorry, I didn't understand that. Try 'query patient <ID>' or 'ask <question>'.")

if __name__ == "__main__":
    chatbot()
