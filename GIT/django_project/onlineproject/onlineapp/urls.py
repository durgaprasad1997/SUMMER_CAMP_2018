from django.urls import path
from . import backup_views
from . import backup_views
from .views import *

app_name="onlineapp"

urlpatterns = [
    path('colleges/',CollegeView.as_view(),name = 'colleges'),

    path('colleges/add_college/', CreateCollegeView.as_view(),name='add_college'),
    path('colleges/<str:Acronym>/add_student/', CreateStudentView.as_view(),name='add_student'),


    path('colleges/<str:Acronym>/',CollegeDetailView.as_view(),name='College_Acronym'),
    path('colleges/<int:pk>/delete/',DeleteCollegeView.as_view(),name='college_delete'),
    path('colleges/<int:pk>/edit/', UpdateCollegeView.as_view(), name='college_edit'),


    path('colleges/<str:Acronym>/<int:pk>/edit/', UpdateStudentView.as_view(), name='student_edit'),

    path('colleges/<str:Acronym>/<int:pk>/delete/',DeleteStudentView.as_view(),name='student_delete'),

    path('exceptionsession/', backup_views.exceptiontest),
    path('testsession/', backup_views.testSession),
    path('studentmarks/', backup_views.queryMarks),
    path('studentdetails/', backup_views.query3),
    path('studentdetails/<int:num>/', backup_views.query3_id),
    path('q2/', backup_views.query2),
    path('q1/', backup_views.query),
    path('game/', backup_views.index),
    path('greet/', backup_views.get),

]