namespace MyProject
{
    partial class Patient_Functionalities
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.reserve = new System.Windows.Forms.Button();
            this.askquestion = new System.Windows.Forms.Button();
            this.searchquestion = new System.Windows.Forms.Button();
            this.update = new System.Windows.Forms.Button();
            this.searchhosp = new System.Windows.Forms.Button();
            this.searchmed = new System.Windows.Forms.Button();
            this.askdonation = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // reserve
            // 
            this.reserve.Font = new System.Drawing.Font("Arial", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.reserve.Location = new System.Drawing.Point(205, 25);
            this.reserve.Name = "reserve";
            this.reserve.Size = new System.Drawing.Size(367, 58);
            this.reserve.TabIndex = 0;
            this.reserve.Text = "Make a reservation";
            this.reserve.UseVisualStyleBackColor = true;
            this.reserve.Click += new System.EventHandler(this.reserve_Click);
            // 
            // askquestion
            // 
            this.askquestion.Font = new System.Drawing.Font("Arial", 26.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.askquestion.Location = new System.Drawing.Point(205, 89);
            this.askquestion.Name = "askquestion";
            this.askquestion.Size = new System.Drawing.Size(367, 57);
            this.askquestion.TabIndex = 1;
            this.askquestion.Text = "Ask a question";
            this.askquestion.UseVisualStyleBackColor = true;
            this.askquestion.Click += new System.EventHandler(this.askquestion_Click);
            // 
            // searchquestion
            // 
            this.searchquestion.Font = new System.Drawing.Font("Arial", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.searchquestion.Location = new System.Drawing.Point(205, 156);
            this.searchquestion.Name = "searchquestion";
            this.searchquestion.Size = new System.Drawing.Size(367, 55);
            this.searchquestion.TabIndex = 2;
            this.searchquestion.Text = "Search for a question";
            this.searchquestion.UseVisualStyleBackColor = true;
            this.searchquestion.Click += new System.EventHandler(this.searchquestion_Click);
            // 
            // update
            // 
            this.update.Font = new System.Drawing.Font("Arial", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.update.Location = new System.Drawing.Point(205, 449);
            this.update.Name = "update";
            this.update.Size = new System.Drawing.Size(367, 51);
            this.update.TabIndex = 10;
            this.update.Text = "Update your information";
            this.update.UseVisualStyleBackColor = true;
            this.update.Click += new System.EventHandler(this.update_Click);
            // 
            // searchhosp
            // 
            this.searchhosp.Font = new System.Drawing.Font("Arial", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.searchhosp.Location = new System.Drawing.Point(205, 375);
            this.searchhosp.Name = "searchhosp";
            this.searchhosp.Size = new System.Drawing.Size(367, 47);
            this.searchhosp.TabIndex = 9;
            this.searchhosp.Text = "Search for hospital";
            this.searchhosp.UseVisualStyleBackColor = true;
            this.searchhosp.Click += new System.EventHandler(this.searchhosp_Click);
            // 
            // searchmed
            // 
            this.searchmed.Font = new System.Drawing.Font("Arial", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.searchmed.Location = new System.Drawing.Point(205, 295);
            this.searchmed.Name = "searchmed";
            this.searchmed.Size = new System.Drawing.Size(367, 51);
            this.searchmed.TabIndex = 8;
            this.searchmed.Text = "Search for medicine";
            this.searchmed.UseVisualStyleBackColor = true;
            this.searchmed.Click += new System.EventHandler(this.searchmed_Click);
            // 
            // askdonation
            // 
            this.askdonation.Font = new System.Drawing.Font("Arial", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.askdonation.Location = new System.Drawing.Point(205, 217);
            this.askdonation.Name = "askdonation";
            this.askdonation.Size = new System.Drawing.Size(367, 58);
            this.askdonation.TabIndex = 7;
            this.askdonation.Text = "Ask for donation";
            this.askdonation.UseVisualStyleBackColor = true;
            this.askdonation.Click += new System.EventHandler(this.askdonation_Click);
            // 
            // Patient_Functionalities
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::MyProject.Properties.Resources.images__2_;
            this.ClientSize = new System.Drawing.Size(777, 538);
            this.Controls.Add(this.update);
            this.Controls.Add(this.searchhosp);
            this.Controls.Add(this.searchmed);
            this.Controls.Add(this.askdonation);
            this.Controls.Add(this.searchquestion);
            this.Controls.Add(this.askquestion);
            this.Controls.Add(this.reserve);
            this.Name = "Patient_Functionalities";
            this.Text = "Patient_Functionalities";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button reserve;
        private System.Windows.Forms.Button askquestion;
        private System.Windows.Forms.Button searchquestion;
        private System.Windows.Forms.Button update;
        private System.Windows.Forms.Button searchhosp;
        private System.Windows.Forms.Button searchmed;
        private System.Windows.Forms.Button askdonation;
    }
}