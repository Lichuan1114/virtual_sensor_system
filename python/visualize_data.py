import pandas as pd
import matplotlib.pyplot as plt
import os

SENSOR_TYPES = {
    "motion": 1,
    "temperature": 2,
    "light": 3
}

# Directory to save plots
SAVE_DIR = "./plots"  

# Ensure the save directory exists
os.makedirs(SAVE_DIR, exist_ok=True)

def load_data(csv_file_path):
    """
    Load the CSV file with pre-processing.
    """
    data = pd.read_csv(csv_file_path, skipinitialspace=True)
    data['Timestamp'] = pd.to_datetime(data['Timestamp'])
    return data

def generate_line_plot(data, sensor_type, sensor_name, y_label, color, save_name=None):
    """
    General function to generate line plot, for temperature and light sensors data.
    """
    # Filter data by sensor type
    sensor_data = data[data['Sensor Type'] == sensor_type].copy()
    
    # Plot the data
    plt.figure(figsize=(10, 6))
    plt.plot(sensor_data['Timestamp'], sensor_data['Data'], label=sensor_name, color=color)
    plt.title(f"{sensor_name} Sensor Data Over Time")
    plt.xlabel("Timestamp")
    plt.ylabel(y_label)
    plt.xticks(rotation=45)
    plt.legend()
    plt.grid()
    plt.tight_layout()
    
    # Save the plot if save_name is provided
    if save_name:
        save_path = os.path.join(SAVE_DIR, save_name)
        plt.savefig(save_path)
        print(f"{sensor_name} graph saved at: {save_path}")
    

def generate_scatter_plot(data, start_time, end_time, save_name=None):
    """
    Function to generate scatter plot, for motion data.
    """
    # Filter motion sensor data
    motion_data = data[data['Sensor Type'] == SENSOR_TYPES['motion']]
    motion_data = motion_data[(motion_data['Timestamp'] >= start_time) & (motion_data['Timestamp'] <= end_time)]
    
    # Plot motion sensor data as a scatter plot
    plt.figure(figsize=(10, 6))
    plt.scatter(motion_data['Timestamp'], motion_data['Data'], label='Motion Detected', color='blue', alpha=0.7)
    plt.title("Motion Sensor Data Over Time")
    plt.xlabel("Timestamp")
    plt.ylabel("Motion Detected (0=No, 1=Yes)")
    plt.xticks(rotation=45)
    plt.yticks([0, 1], labels=["No Motion", "Motion Detected"])  
    plt.legend()
    plt.grid()
    plt.tight_layout()
    
    # Save the plot if save_name is provided
    if save_name:
        save_path = os.path.join(SAVE_DIR, save_name)
        plt.savefig(save_path)
        print(f"Motion graph saved at: {save_path}")
    

def main(csv_file_path):
    # Load data
    data = load_data(csv_file_path)
    
    # Generate plots for each sensor type
    generate_line_plot(
        data, 
        sensor_type=SENSOR_TYPES["temperature"], 
        sensor_name="Temperature", 
        y_label="Temperature (°C)", 
        color="orange",
        save_name="temperature_plot.png"
    )
    generate_line_plot(
        data, 
        sensor_type=SENSOR_TYPES["light"], 
        sensor_name="Light Intensity", 
        y_label="Light Intensity (lux)", 
        color="blue",
        save_name="light_plot.png"
    )
    generate_scatter_plot(
        data, 
        start_time=pd.to_datetime("2024-12-23 10:30:00"),
        end_time=pd.to_datetime("2024-12-23 10:35:00"),
        save_name="motion_plot.png"
    )

if __name__ == "__main__":
    csv_file_path = "../cpp/output/sensor_logs.csv"
    main(csv_file_path)
